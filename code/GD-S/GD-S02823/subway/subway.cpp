#include<bits/stdc++.h>
using namespace std;
unsigned long long c,n,m,d,q,w[600000],k[600000],a[600000][60],t[600000][60],x,y,ans[200000],l_1,j_1,r_1;
bool ok1=false,ok2=false;
int main()
{
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++)
			scanf("%lld%lld",&a[i][j],&t[i][j]);
	}
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld",&x,&y);
		ans[i]=ans[i]+w[x]+w[y];
		for(int j=1;j<=n;j++)
			if(a[j][x]!=0&&a[j][y]!=0) {ok1=true;j_1=j;}
		if(ok1) ans[i]=ans[i]+t[j_1][x]+t[j_1][y];
		else 
		{
			unsigned long long l=1,r=1;
			while(l<=n&&r<=m) 
			{
				l++;
				if(a[l][x]!=0&&a[l][r]!=0) {ok2=true;l_1=l,r_1=r;}
				else r++;
				if(ok2&&a[l][r]!=0&&a[l][y]!=0) break;
			}
			ans[i]=ans[i]+t[l_1][x]+t[l_1][r_1]+t[l][r_1]+t[l][y];
		}
	}
	for(int i=1;i<=q;i++)
		cout<<ans[i]<<" "<<endl;
	return 0;
}
