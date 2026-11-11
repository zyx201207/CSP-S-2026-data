#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin)
	freopen("crystal.out","w",stdout)
	
	int n;
	int m;
	int an;
	cin>>n>>m;
	cin>>an;
	int ans=0;
	
	for(int i=1;i<n;i++)
	{
		int sum=n+1;
		ans+=sum;
	}
	for(int j=1;j<m;j++)
	{
		int num=n+1;
		ans+=num;
	}
	
	cout<<ans<<endl;
	
	return 0;
}
