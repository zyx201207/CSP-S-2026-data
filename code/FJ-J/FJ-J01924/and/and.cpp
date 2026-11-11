#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("and.in","r");
	freopen("and.out","w");
	long long n,m,ans=0,a[10005];
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i];
		if(i==4)
		{
			ans=a[i];
		}
	}
	cout<<ans;
	return 0;
}
