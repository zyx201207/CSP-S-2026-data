#include <bits/stdc++.h>
using namespace std;
int n,m;
int zuobiao[2000010];
int cnt;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
		int a1,a2,qidian=cnt+1,ans=0;
		cin>>a1>>a2;
		for(int j=1;j<=a1;j++)
		{
			cin>>zuobiao[++cnt];
		}
		for(int j=qidian;j<cnt;j++)
		{
			for(int k=j+1;k<=cnt;k++)
			{
				int num=0;
				for(int p=j+1;p<k;p++)
				{
					if(zuobiao[p]-zuobiao[j]<=a2&&zuobiao[k]-zuobiao[p]<=a2)
					{
						num++;
					}
				}
				if(num==2)
				ans++;
			}
		}
		cout<<ans;
		if(i!=m)
		cout<<'\n';
	}
    return 0;
}
