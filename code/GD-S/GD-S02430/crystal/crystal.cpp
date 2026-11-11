#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mn=5e5+5;
ll n,m,a[mn],lt=1,sm,ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++){
		sm+=(a[i]-a[i-1])*(i-lt);
		while(sm>m){
			sm-=a[i]-a[lt];
			lt++;
		}ans=max(ans,i-lt+1);
		//cout<<i<<':'<<lt<<'\n';
	}cout<<ans;
	return 0;
}/*
5 8
-3 -1 2 2 7
*/
