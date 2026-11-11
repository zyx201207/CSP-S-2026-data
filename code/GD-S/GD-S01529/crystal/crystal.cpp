#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[600000],cnt=0,sum=0,b[600000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ll l=ceil(n/2);
	for(int i=1;i<=n;i++)b[i]=abs(a[l]-a[i]);
	sort(b+1,b+n+1);
	
	for(int i=1;i<=n;i++){
		if(cnt+b[i]<=m)cnt+=b[i],sum++;
	}
	cout<<sum;
	return 0;
}
