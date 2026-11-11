#include<bits/stdc++.h>
using namespace std;
int a[2000010];
int main()
{
	//please give me AC
	freopen("migrate.in","r",stdin);
	freopen("mugrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,k,ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=3;i<=2*k;i+=2)
		{
			for(int l=1;l<=n;l++)
			{
				if(l+i<=n)
				{
					ans++;
				}
				else break;
			}
		}
		cout<<ans;
	}
	return 0;
}
