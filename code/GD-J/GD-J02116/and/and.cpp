#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ull> pll;
const int maxn = 2e5 + 5;
inline ll read(){
	ll x = 0;
	char ch = getchar();
	while(ch < '0' || ch > '9'){
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9'){
		x = (x << 3) + (x << 1) + (ch ^ 48);
		ch = getchar();
	}
	return x;
}
int n,m;
int num[40]; // 每个比特1的出现次数 
ll ans;
pll a[maxn]; // 第一个是值，第二个是权值 
inline void Cuora(ll x){ // 统计比特次数 
	ll temp;
	for(int i = 0;i <= 31;i++){
		temp = 1LL << i;
		if(x & temp){
			num[i]++;
		}
	}
	return ;
}
inline ull Turtle(ll x){ // 计算权重 
	ull temp,res = 0;
	for(int i = 0;i <= 31;i++){
		temp = 1ULL << i;
		if(x & temp){
			res += num[i] * temp;
		}
	}
	return res;
}
bool cmp(const pll &aa,const pll &bb){
	if(aa.second != bb.second) return aa.second > bb.second;
	return aa.first > bb.first;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n = read(),m = read();
	for(int i = 1;i <= n;i++){
		a[i].first = read();
		Cuora(a[i].first);
	}
	for(int i = 1;i <= n;i++){
		a[i].second = Turtle(a[i].first);
	}
	sort(a + 1,a + 1 + n,cmp);
	//for(int i = 1;i <= n;i++) printf("第%d个数为%lld，权值为%llu\n",i,a[i].first,a[i].second);
	//for(int i = 0;i <= 31;i++) printf("第%d个比特有%d个1\n",i,num[i]);
	ans = a[1].first;
	for(int i = 2;i <= m;i++){
		ans &= a[i].first;
	}
	printf("%lld\n",ans);
	return 0;
}
