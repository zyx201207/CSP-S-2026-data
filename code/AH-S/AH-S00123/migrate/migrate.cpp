#include<bits/stdc++.h>

using namespace std;

long long a[2000010];

int main()
{

	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		long long n,m;
		cin>>n>>m;
		int i,j,k;
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		long long ans=0;
		long long back,front;
		back=front=0;
		for(i=1;i<=n-3;i++)
		{
			j=1;
			while(i+2*j+1<=n)
			{
				if((a[i+2*j]-a[i]<=m)&&(a[i+2*j+1]-a[i+1]<=m)&&(a[i+2*j+1]-a[i]>m))
				{
					k=i;
					back=0;
					while((k>1)&&(a[k]-a[k-2]>m))
					{
						k--;
						back++;
					}
					ans+=back+1;
					front=0;
					k=i+2*j+1;
					while(a[k+2]-a[k]>m)
					{
						k++;
						front++;
						ans+=back;
					}
				}
				else
				{
					break;
				}
				j++;
			}
		}
		cout<<"THIS IS ANS:!!!"<<ans<<endl;
	}

	return 0;
}
