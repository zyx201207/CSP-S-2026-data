#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],d[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		memset(d,0,sizeof(d));
		for(long long i=1;i<=n;i++){
			d[i]=a[i]-a[i-1];
		}
		long long ans=-1;
		for(long long i=2;i<=n;i++){
			long long b=1,h=0,j=i;
			while(h<=m){
				h+=d[j]*b;
				b++;
				j++;
				if(j>n) break;
			}
			ans=max(ans,b-1);
		}
		cout<<ans;
	}
	else{
		memset(d,0,sizeof(d));
		for(long long i=1;i<=n;i++){
			d[i]=a[i]-a[i-1];
		}
		long long b=1,h=0,ans=-1;
		for(long long i=2;i<=n;i++){
			if(h>m){
				ans=max(ans,b-1);
				b=1;
				h=0;
			}
			h+=d[i]*b;
			b++;
		}
		ans=max(ans,b-1);
		cout<<ans;
	}
	return 0;
}
