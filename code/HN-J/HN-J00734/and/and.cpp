#include<bits/stdc++.h> 
using namespace std;
int dp[200005],a[200005];
int m,n;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==2) cout<<a[n] and a[n-1];
	else cout<<a[n];
	return 0;
}
/*
4 2 
3 15 12 12
*/
