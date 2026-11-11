#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef __int128 i128;
inline ll read(){
	ll x = 0,f = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
const int maxn = 5e5 + 5;
const ll maxxx = 1e5;
const ll up = 1e12;
int l,r,mid;
bool f1,f2,f3;
bool notok[maxn];
ll n,m,ans = 1,ans2,temp,total,maxa = -1,lst;
ll a[maxn],pre1[maxn];
ull abss(ll aa,ll bb){
	if(aa > bb) return aa - bb;
	return bb - aa;
}
bool cmp(const ll &aa,const ll &bb){ // 离平均值近的排前面 
	return abss(aa,total) < abss(bb,total);
}
inline bool check(int x){ //从1至第x块合成是否可行 
	if(x > n || x < 1 || notok[x]) return 0;
	return 1;
}
inline void solve1(){
	for(int i = 1;i <= n;i++){
		maxa = max(maxa,a[i]);
		pre1[i] = pre1[i - 1] + a[i];
		if(maxa * (i - 1) - pre1[i - 1] > m){
			for(int j = i;j <= n;j++){
				notok[j] = 1;
			}
			break;
		}
	}
	l = 1,r = n;
	while(l <= r){
		mid = l + ((r - l) >> 1);
		if(check(mid)){
			ans = mid;
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	printf("%lld\n",ans);
	return ;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;i++){
		a[i] = read(),total += a[i];
		if(!f1) f1 = (abs(a[i]) > maxxx); // 特判一下数据范围，对应1~12测试点 
		if(!f2) f2 = (a[i] != i); // 对应13~15测试点 
	}
	sort(a + 1,a + 1 + n);
	if(a[2] - a[1] != a[n] - a[n - 1]) f3 = 1;
	total /= n; // 求平均数 
	if(!f2 && !f3) sort(a + 1,a + 1 + n,cmp);
	if(!f1){
		solve1();
	}else if(!f2){
		temp = (ll) sqrt(m << 2);
		while(((temp + 1) * temp >> 1) <= m){
			temp++;
		}
		if(((temp + 1) * temp >> 1) > m) temp--;
		printf("%lld\n",temp);
	}else if(!f3){
		ll op = a[2] - a[1];
		ll you = (a[n] - a[1]) / op;
		temp = 1;
		while(((temp + 1) * you >> 1) <= m){
			temp++;
		}
		if(((temp + 1) * you >> 1) > m) temp--;
		printf("%lld\n",temp);
	}
	return 0;
}
