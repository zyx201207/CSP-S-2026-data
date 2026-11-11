#include<bits/stdc++.h>
using namespace std;
long long a[10000005];
long long b[10000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];		
	}
	if(m==1)
	{
		cout<<0;
	}
	else
	{
		cout<<a[n-1];
	}
	
	return 0;

}
