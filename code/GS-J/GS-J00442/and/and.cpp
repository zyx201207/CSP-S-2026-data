#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005];
int main()
{
	//freopen("and.in","r",stdin)
	//freopen("and.out","w",stdout)
	cin>>n>>m;
	for(int i=0;i<=n;i++)
	{
	    cin>>a[i];	
	}
	int minn=100;
	for(int i=0;i<=n;i++)
	{
		if(minn>a[i])
		{
			minn=a[i];
		} 
	}
	cout<<minn;
	return 0;
}
