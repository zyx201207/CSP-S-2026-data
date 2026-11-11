#inslude<iostream>
#inslude<string>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,y;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<i;j++)
		{
			if(a[j]<a[j+1])
			{
				y=a[j];
				a[j]=a[j+1];
				a[j+1]=y;
			}
		}
	}
	y=a[1];
	for(int i=2;i<=m;i++)
	{
		y=y and a[i];
	}
	cout<<y;
	return 0;
}
