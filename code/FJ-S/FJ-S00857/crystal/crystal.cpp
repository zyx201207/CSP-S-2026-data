#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int num[N];
ll a[N];
int n;
ll m;
ll app(int i,ll maxn,ll k,int sj){
//	cout<<i<<' '<<maxn<<' '<<k<<' '<<sj<<'\n'; 
	if(i>n){
		if(maxn*sj>=k && maxn*sj<=k+m && sj>0){
			return sj;
		}
		return 1;
	}
	return max(app(i+1,max(maxn,a[i]),k+a[i],sj+1),app(i+1,maxn,k,sj));
//	return app(i+1,maxn,k,sj);
//	return app(i+1,max(maxn,a[i]),k+a[i],sj+1);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<app(1,0,0,0);
	return 0;
} 
/*
5 8
-3 -1 2 2 7

5 5
1 2 4 8 9
*/
