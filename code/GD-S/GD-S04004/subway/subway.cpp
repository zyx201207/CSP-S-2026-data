#include<iostream>
using namespace std;
int a[100005];
int b[5005][5005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,d,q,z;
	cin>>n>>m>>d>>z>>q;
	for(int i=1;i<=d;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
		int y;
		for(int j=1;j<=k;j++)
		{
			int x;
			cin>>x;
			if(j==1)
			{
				y=x;
				cin>>b[j][x];
			}
			else
			{
				cin>>b[j][x];
			}
			
		}
	}
	int l,r;
	long long sum=0;
	for(int i=1;i<=q;i++)
	{
		sum=0;
		cin>>l>>r;
		sum+=a[l];
		sum+=b[1][l]; 
		for(int j=l+1;j<=r;j++)
		{
			int min1=1e9;
			for(int k=1;k<=m;k++)
			{
				min1=min(b[k][j],min1);
			}
			sum+=min1;
		}
		sum+=a[r];
		cout<<sum<<"\n";
	}
	return 0;
} 
