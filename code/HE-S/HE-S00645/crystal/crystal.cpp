#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=6e5+5;
int n;
int a[maxn];
int su[maxn];
int m;
int cost;
int l,r;
void add(){
	++r;
	cost=cost+(a[r]-a[r-1])*(r-l);
}
void sub(){
	cost=cost-(a[r]-a[l]);
	++l;
}
int ans;
void solve(){
	ans=0;
	l=1,r=0;
	while(r<=n){
		add();
		if(cost>m){
			do{
				sub();
			}while(cost>m);
		}else ans=max(ans,r-l+1);
	}
}
signed main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	solve();
	cout<<ans;
	return 0;
}
