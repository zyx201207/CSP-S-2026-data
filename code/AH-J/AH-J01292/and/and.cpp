#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,vmax;
long long ans;
long long a[N],cnt[35],d[N];
bool b[N][35],c[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i];
		d[i]=a[i];
		int k=1;
		while(a[i]!=0)
		{
			  if(a[i]%2==1)
			  {
			  	 b[i][k]=1;
			  	 cnt[k]++;
			  }
			  a[i]/=2;
			  vmax=max(vmax,k);
			  k++;
		}
	}
	for(int i=vmax;i>=1;i--)
	{
		int sum=0;
		if(cnt[i]<m)
		{
		   continue;
		}
		for(int j=1;j<=n;j++)
		{
			if(c[j]==1)
			{
			   continue;
			}
			if(b[j][i]==0)
			{
			   c[j]=1;
			   for(int tt=1;tt<=30;tt++)
			   {
			   	   if(b[j][tt]==1)
			   	   {
			   	   	  cnt[tt]--;
			   	   	  b[j][tt]=0;
				   }
			   	   
			   }
			}
		}
	}
	int t=0;
	for(int i=1;i<=n;i++)
	{
		if(t==m)
		{
		   break;
		}
		if(c[i]==0&&t==0)
		{
		   ans=d[i];
		   t++;
		}
		else if(c[i]==0)
		{
			    ans&=d[i];
			    t++;
		}
	}
	cout<<ans;
	return 0;
}

