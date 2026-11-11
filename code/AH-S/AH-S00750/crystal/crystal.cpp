#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans=0;
ll a[500009],k[500009];

ll add(ll l,ll r){
	ll re=k[r-1];
	//cout<<re<<endl;
	re-=a[r]*(r-1);
	//cout<<re<<endl;
	if(l==1)return -re;
	re+=a[r]*(l-1);
	//cout<<re<<endl;
	re-=k[l-1];
	return -re;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//cout<<LONG_LONG_MAX;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1,data=a[1];i<=n;i++){
		a[i]+=data;
		k[i]=k[i-1]+a[i];
	}
	//for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)cout<<i<<' '<<j<<' '<<add(i,j)<<endl;
	
	for(ll l=1,r=1;r<=n;r++){
		if(add(l,r)>m)l++;
		else{
			ans=max(ans,r-l+1);
			//cout<<l<<' '<<r<<' '<<r-l+1<<endl;
		}
	}
	
	cout<<ans;
	return 0;
}
