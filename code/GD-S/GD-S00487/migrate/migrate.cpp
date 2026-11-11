#include<bits/stdc++.h>
using namespace std;
int cc,t,n,b[2000005],d[2000005],f[2000005],x,y;
long long kk,a[2000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>cc>>t;
	while(t--){
		cin>>n>>kk;
		if(n>5000){
			cout<<n-kk<<"\n";continue;
		}
		ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			d[i]=0;f[i]=1;
			for(int j=i+1;j<=n;j++)
			{
				d[j]=1e9;f[j]=0;
				for(int k=j-1;k>=i;k--)
				{
					if(a[j]-a[k]>kk)break;
					if(d[j]==d[k]+1)f[j]+=f[k];
					else if(d[j]>d[k]+1)d[j]=d[k]+1,f[j]=f[k];
				}
				if(f[j]==2)ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
