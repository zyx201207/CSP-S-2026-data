#include<bits/stdc++.h>
using namespace std;
int s[200001][35];
bool f[200001];
void cl(int t,int x)
{
	int xx=x,o,k=0;
	while(xx>0)
	{
		o=xx&(-xx);
		while(pow(2,k)!=o)
		k++;
		k++;
		s[t][k]++;
		xx-=o;
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a,ans=0,z=0,w=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		f[i]=true;
		cl(i,a);
	}
	for(int i=31;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[j][i]==1&&f[j])
			z++;
			else if(s[j][i]==0)
			f[j]=false;
		}
		if(z>=m)
		{
			w++;
			ans+=pow(2,i-1);
		}
		else if(w==0)
		{
			for(int j=1;j<=n;j++)
			f[j]=true;
		}
		z=0;
	}
	printf("%d",ans);
	return 0;
}
