#include<bits/stdc++.h>
using namespace std;
int c,T;
long long n,d,a[100005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		int cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n&&i>j;j++)
			{
				long long f[100005],num=1;
				long long dis=a[i]-a[j],tmp=0;
				if(dis<=d) continue;
				for(int k=j+1;k<=i;k++)
				{
					f[num++]=a[k]-a[k-1];
				}
				for(int k=2;k<num;k++)
				{
					if(f[k]+f[k-1]<=d)
					{
						tmp++;
					}
					if(f[k]>d)
					{
						tmp=0;
						break;
					}
				}
				if(tmp==2&&f[1]<=d)
				{
					cout<<i<<" "<<j<<endl;
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
