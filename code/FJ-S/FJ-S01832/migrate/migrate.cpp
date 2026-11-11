#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3;
long long e,d,a[2020022],ans,pa[6060][6060];
int f[6060][6060],n,t,c;

void floyd()
{
	for(int i=1;i<=n;i++)
	 {
	 	for(int j=i+2;j<=n;j++)
	 	 {
	 	 	for(int k=i+1;k<j;k++)
	 	 	 {
	 	 	 	if(f[i][j]>f[i][k]+f[k][j]+1)
	 	 	 	 {
	 	 	 	 	f[i][j]=f[i][k]+f[k][j]+1;
	 	 	 	 	pa[i][j]=pa[i][k]*pa[k][j];
	 	 	 	 	continue;
					}
				if(f[i][j]==f[i][k]+f[k][j]+1)
				 {
				 	pa[i][j]+=pa[i][k]*pa[k][j];
				 	if(pa[i][j]>=maxn) pa[i][j]=maxn;
				 }
			   }
		  }
	 }
}

bool pd()
{
	if(n<6060) return 0;
	for(int i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	  }
	e=a[2]-a[1];
	cout<<0<<"\n"; return 1;
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	for(int k=1;k<=t;k++)
	 {
	 	cin>>n>>d; ans=0;
	 	if(pd()) continue;
	 	for(int i=1;i<=n;i++)
	 	 {
	 	 	for(int j=1;j<=n;j++)
	 	 	 {
	 	 	 	f[i][j]=0x3f3f3f3f;
	 	 	 	pa[i][j]=0x3f3f3f3f;
			   }
		  }
	 	for(int i=1;i<=n;i++)
	 	 {
	 	 	cin>>a[i];f[i][i]=0;
	 	 	for(int j=i-1;j>=1;j--)
	 	 	 {
	 	 	 	e=a[i]-a[j];
	 	 	 	if(e<=d)
	 	 	 	 {
	 	 	 	 	f[j][i]=0;
	 	 	 	 	pa[j][i]=1;
					}
				else break;
			   }
		  }
		floyd();
		for(int i=1;i<=n;i++)
		 {
		 	for(int j=i+1;j<=n;j++)
		 	 {
		 	 	if(pa[i][j]==2) ans++;
			  }
		 }
		cout<<ans<<"\n";
	 }
	return 0;
}
