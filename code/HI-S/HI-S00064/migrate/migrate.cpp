#include<bits/stdc++.h>
using namespace std;
int a[100005];
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				int road=0;
				for(int k=i+1;k<j;k++)
				{
					if(a[k]-a[i]<=d&&a[j]-a[k]<=d)
					{
						road++;
					}
				}
				if(road==2&&i-j>d) ans++;
			}
		}
		cout<<ans;
	}
	return 0;
}

