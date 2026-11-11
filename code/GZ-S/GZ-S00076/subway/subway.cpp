//GZ-S00076 ³Âóããå
#include<bits/stdc++.h>
using namespace std;
const int N=50001;
int c,n,m,d,q,pla[N],lp[N][N],lt[N][N];
int main()
{
	freopen("subway.in",r,stdin);
	freopen("subway.out",w,stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>pla[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;for(int j=1;j<=k;j++) cin>>lp[i][j]>>lt[i][j];
	}
	while(q--)
	{
		int st,ed;
		cin>>st>>ed;
		int ans=0;
		ans= pla[st]+pla[ed];
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=1001;j++)
			{
				if(lp[i][j]==st)
				{
					ans+=lt[i][j];
					int k=i; 
				}
				if(lp[i][j]==ed)
				{
					ans+=lt[i][j];
					if(i==k)
					{
						cout<<ans<<endl;
					}
				}
				
			}
		}
	}
	fclose(stdin); 
	fclose(stdout);
	return 0;
}
