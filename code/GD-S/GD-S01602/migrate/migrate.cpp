#include<bits/stdc++.h>

using namespace std;

int c,t,ans;


void dfs(int un,int vn,int ansa)
{

}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin >>c>>t;
	
	for (int i=0;i<t;i++)
	{
		int n,d,xn[2000005],xyn[2000005][2000005];
		cin >> n>>d;
		for(int j=0;j<n;j++)
		{
			cin>>xn[j];
			for (int k=0;k<n;k++)
			{
				int dd=0;
			dd=(xn[j]-xn[k]>0?xn[j]-xn[k]:xn[k]-xn[j]);
			xyn[j][k]=dd;
			}
		
		}
		for (int l=0;l<n-2;l++)
		{
			for (int m=l;m<n;m++)
			{
				int summin=2e10;
				dfs(xn[l],xn[m],0);
				int aaaa[2000005][2000005];
				for (int p=0;p<n;p++)
				{
					aaaa[p][p]=1;
				}
				for (int o=0;o<summin;o++)
				{
					for (int q=0;q<n;q++)
					{
						for (int r=0;r<n;r++)
						{
							
						}
					}
				}
				if (aaaa[m][l]==2)
				{
					ans++;
				}
			}
		}
	cout << ans;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
