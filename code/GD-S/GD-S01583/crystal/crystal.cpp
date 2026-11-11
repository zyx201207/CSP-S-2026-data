#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],x=1,ans=1,y=1,m1,cnt=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	m1=m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	while(m!=0){
		if(x==n)break;
		if(a[x]<a[x+1])a[x]++,m-=x;
		if(a[x]==a[x+1]){
			cnt++;
			x++;
			if(m<x)break;
		}
	}
	for(int i=1;i<=n-1;i++){
		if(a[i]==a[i+1])y++;
		ans=max(ans,y);
		if(a[i]!=a[i+1]){
			y=1;
		}
	}
	ans+=(cnt)-1;
	if(ans>n)ans=n;
	sort(a+1,a+n+1);
	x=n,m=m1,y=1;
	while(m!=0){
		if(x==0)break;
		if(a[x-1]<a[x])a[x-1]++,m--;
		if(a[x-1]==a[x]){
			x--;
		}
	}
	for(int i=1;i<=n-1;i++){
		if(a[i]==a[i+1])y++;
		ans=max(ans,y);
		if(a[i]!=a[i+1]){
			y=1;
		}
	}
	cout<<ans;
	return 0;
}
