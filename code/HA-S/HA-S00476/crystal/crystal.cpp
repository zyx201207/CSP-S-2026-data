#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m,a[N],c[N],dp[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	c[1]=0;
	ll lj=0,x=0,ans=0;
	for(int i=1;i<=n;i++){
		x=i,lj=0;
		while(lj<m && x<=n){
			lj+=abs(c[x++]);
		}
		if(lj == m){
			ans=max(x-i,ans);
		}else{
			ans=max(x-1-i,ans);
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
