#include<bits/stdc++.h>
using namespace std;
#define N 5500
long long a[N];
long long f[N][N];
long long s[N][N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,T;
	cin>>c>>T;
	while(T--)
	  {
	  	long long n,d;
	  	cin>>n>>d;
	  	for(int i=1;i<=n;i++)
	  	  cin>>a[i];
	  	for(int i=1;i<=n;i++)
	  	  for(int j=i+1;j<=n;j++)
	  	    f[i][j]=2000000000000010000,s[i][j]=1;
	  	for(int i=1;i<=n;i++)
	  	  {
	  	  	for(int j=i+1;j<=n;j++)
	  	  	  {
	  	  	  	if(a[j]-a[i]>d)
	  	  	  	  break;
	  	  	  	f[i][j]=1;
	  	  	  	f[j][i]=1;
			  }
		  }
		for(int i=1;i<=n;i++)
		  for(int j=i+1;j<=n;j++)
		    for(int k=1;k<=n;k++)
		      {
		      	if(i==k||j==k)
		      	  continue;
		      	if(f[i][k]==f[i][j]+f[j][k])
		      	  s[i][k]++;
		      	else if(f[i][k]>f[i][j]+f[j][k])
		      	  {
		      	  	f[i][k]=f[i][j]+f[j][k];
		      	  	s[i][k]=1;
				  }
			  }
		int ans=0;
		for(int i=1;i<=n;i++)
		  for(int j=i+1;j<=n;j++)
		    if(s[i][j]==2)
		      {
		        ans++;
		        //cout<<i<<" "<<j<<" "<<f[i][j]<<" "<<endl;
		      }
		cout<<ans<<endl;
	  }
	return 0;
 } 
