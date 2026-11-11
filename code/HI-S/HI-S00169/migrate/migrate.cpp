#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("migrate1.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c<=10)
	{
		while(t--)
		{
			int ans=0;
			int n,d;cin>>n>>d;
			int x[n+1];
			for(int i=1;i<=n;i++)
			{
				cin>>x[i];
			}
			for(int i=1;i<=n;i++)
			{
				for(int j=i;j<=n;j++)
				{
					if((x[j]-x[i])-d==1&&j-i!=1&&d<=2&&d!=1) 
					{
						ans++;
//						cout<<j<<" "<<i<<endl;
					}
				}
			}
			cout<<ans<<endl;
		}
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
