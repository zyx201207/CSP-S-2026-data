#include<bits/stdc++.h> 
using namespace std;
long long a[500005],b[500005],c[500005],d[500005];
int main(){
	freopen("crystal.in","r",stdin); 
	freopen("crystal.out","w",stdout); 
	long long n,m,s=0,t=1,ans=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)b[i]=a[i]-a[i-1];
	for(int i=1;i<=n;i++)c[i]=c[i-1]+b[i]*(i-1);
	for(int i=n;i>=1;i--)d[i]=d[i+1]+b[i+1];
	for(int i=1;i<=n;i++){
		while(c[i]-s+d[i]*(t-1)>m)s+=d[t++];
		ans=max(ans,i-t+1);
	}cout<<ans;
	return 0;
}
