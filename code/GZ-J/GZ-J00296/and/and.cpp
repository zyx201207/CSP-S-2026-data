//GZ-J00296，贵阳市南明区李端棻中学，任柏翰 
#include<bits/stdc++.h>
using namespace std;  

const int N=2*1e5;
int n,m;
int a[N];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	int ans=a[1];
	for(int i=2;i<=m;i++)
	{
		ans=ans & a[i];
	}
	cout<<ans;
	
	return 0;
}
