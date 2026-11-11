#include<bits/stdc++.h>
using namespace std;
long long n,m,c,d,q,t,x,y;
int a[500005],dian[505][25],time2[505][25],ans[5005][5005];
int main()
{
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		dian[i][1]=t;
		for(int i=2;i<=t+1;i++) 
		{
			cin>>dian[i][t];
			cin>>time2[i][t];
		}
	}
	if(c<=3)
	{
		memset(ans,-1,sizeof(ans));
		long long f[15],zhuan,zt;
		for(int i=1;i<=dian[1][1];i++) f[dian[1][i]]++;
		for(int i=1;i<=dian[2][1];i++) f[dian[2][i]]+=2;
		for(int i=1;i<=10;i++) 
		{
			if(f[i]==3)
			{
				zhuan=i;
				break;
			}
		}
		for(int i=1;i<=dian[1][1];i++) 
		{
			if(dian[1][i]==zhuan) zt=time2[1][i];
		}
		for(int i=1;i<=dian[2][1];i++)
		{
			if(dian[2][i]==zhuan) zt=time2[2][i];
	    }
		for(int k=1;k<=2;k++)
		{
			for(int i=1;i<=dian[k][1];i++) 
			{
				for(int j=i+1;j<=dian[k][1];j++) ans[i][j]=a[i]+a[j]+time2[k][i]+time2[k][j];
			} 
		}
		for(int i=1;i<=10;i++)
		{
			for(int j=1;j<=10;j++)
			{
				if(ans[i][j]==-1)
				{
					ans[i][j]=a[i]+a[j]+time2[f[i]][i]+time2[f[j]][j]+zt;
				}
			}
		}
		while(q--)
		{
			cin>>x>>y;
			cout<<ans[x][y]<<'\n';
		}
	}
	return 0;
}
