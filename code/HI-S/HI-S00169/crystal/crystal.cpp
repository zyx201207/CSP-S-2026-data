#include<bits/stdc++.h>
using namespace std;
const int N=500050;
int a[N];
int n,m;

int main()
{
	freopen("crystal2.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++)
	{
		a[i]=a[i+1]-a[i];
	}

	int maxnum=-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int x;
			x=a[j-1]+a[j]*(j-i+1);
//			cout<<a[j]<<" "<<x<<endl;
			if(x<=m)
				maxnum=max(maxnum,j-i+2);
		}
	}
	cout<<maxnum;
	fclose(stdin);fclose(stdout);
	
	return 0;
}
