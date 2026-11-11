#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int n,m;
bool flaga=1,flagb=1;
bool check(int x){
	for(int i=1;i<=n-x+1;i++){
		int res=0;
		for(int j=i;j<=i+x-2;j++){
			res+=a[i+x-1]-a[j];
		}	
		if(res<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]!=i)flaga=0;
		if(i==1||i==2)continue;
		if(a[i]-a[i-1]!=a[i-1]-a[i-2])flagb=0;
	}
	if(flaga==1){
		int mx=1;
		for(int i=1;i<=n-1;i++){
			if((1+i)*i/2<=m)mx=i+1;
		}
		cout<<mx;
		return 0;
	}
	if(flagb==1){
		int mx=1,back=a[2]-a[1];
		for(int i=1;i<=n-1;i++){
			if((1+i)*i/2*back<=m)mx=i+1;
		}
		cout<<mx;
		return 0;
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
