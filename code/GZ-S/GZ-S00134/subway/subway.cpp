//GZ-S00134,刘雨航,北京师范大学贵阳附属中学 
#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,a[5500][5500],w[55000],i,j,kk,k,fr,ti;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::cin.tie(0);
	std::cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++)cin>>w[i];
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=m;j++)
		{
			a[i][j]=10000000010;
		}
	}
	for(i=1;i<=n;i++)
	{
		cin>>kk;
		long long t[55000]={},tt[55000]={};
		for(j=1;j<=kk;j++)
		{
			cin>>fr>>ti;
			t[j]=fr;
			tt[j]=ti;
		}
		for(j=1;j<=kk;j++)
		{
			for(k=j+1;k<=kk;k++)
			{
				//if(a[t[j]][t[k]]>tt[j]+tt[k])cout<<t[j]<<"号"<<t[k]<<"号"<<a[t[j]][t[k]]<<"用时"<<endl;
				a[t[j]][t[k]]=min(a[t[j]][t[k]],tt[j]+tt[k]);
				
			}
		}
	}//floyd;
	for(k=1;k<=m;k++)
	{
		for(i=1;i<=m;i++)
		{
			for(j=i;j<=m;j++)
			{
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	}
	for(i=1;i<=q;i++)
	{
		cin>>fr>>ti;
		cout<<w[fr]+w[ti]+min(a[fr][ti],a[ti][fr])<<endl;
	}
	return 0;
}
