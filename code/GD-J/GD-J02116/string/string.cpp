#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
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
ll n,cnt = -1,awa,num,l,r,need;
string temp;
char c,lst = '!',c1,c2;
pair<ll,char> a[maxn]; // 第一个存数量，第二个存具体字符 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int i = 1;i <= n;i++){ // 相邻两段一样的就合并 
		cin >> awa >> temp;
		c = temp[0];
		if(c != lst){
			a[++cnt] = {num,lst};
			num = awa;lst = c;
		}else{
			num += awa;
		}
	}
	a[++cnt] = {num,lst};
	//for(int i = 1;i <= cnt;i++) cout << a[i].first << " " << a[i].second << "\n";
	int i = 1,j = cnt;
	l = a[i].first,r = a[j].first;
	while(i <= j){
		c1 = a[i].second,c2 = a[j].second;
		if(c1 != c2){ // 字符不相等，有代价 
			if(l < r){
				need += l;
				r -= l;
				l = a[++i].first;
			}else if(l > r){
				need += r;
				l -= r;
				r = a[--j].first;
			}else{
				need += l;
				i++;j--;
				l = a[i].first,r = a[j].first;
			}
			//cout << "c1 = " << c1 << " c2 = " << c2 << " l = " << l << " r = " << r << " i = " << i << " j = " << j << "\n"; 
		}else{ //字符相等，无代价 
			if(l < r){
				r -= l;
				i++;
				l = a[i].first;
			}else if(l > r){
				l -= r;
				j--;
				r = a[j].first;
			}else{
				i++;j--;
				l = a[i].first,r = a[j].first;
			}
			//cout << "c1 = " << c1 << " c2 = " << c2 << " l = " << l << " r = " << r << " i = " << i << " j = " << j << "\n"; 
		}
	}
	//cout << "l = " << l << " r = " << r << "\n";
	cout << need << "\n";
	//need += abs(l - r);
	//cout << need << "\n";
	return 0;
}
