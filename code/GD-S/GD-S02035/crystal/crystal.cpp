#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int MAXN=5e5+8;
ll n,m;
ll a[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bool flagB=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2)
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])
				flagB=0;	
	}
	sort(a+1,a+n+1);
	if(flagB){
		ll ans=0,mmax=1;
		ll carry=a[2]-a[1];
		while(ans<m){
			ans+=mmax*carry;
			mmax++; 
		}
		if(ans==m)
			cout<<mmax;
		else
			cout<<mmax-1;
		return 0;
	}
	
	ll mmax=-1;
	for(int i=n;i>=1;i--){
		ll ans=1;
		ll x=m;
		for(int j=i-1;j>=1;j--){
			if(x-(a[i]-a[j])>=0)
				ans++,x-=(a[i]-a[j]);	
			else
				break;		
		}
		mmax=max(mmax,ans);
	}
	cout<<mmax;
	return 0;
}
/*
5 5
1 2 4 8 9


5 8
-3 -1 2 2 7
*/
