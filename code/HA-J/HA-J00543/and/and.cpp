#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen ("and.in","r",stdin);
//	freopen ("and.out","w",stdout);
	string s;
	int n,m,sum=0;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>s[i];
	}
	if (s[0]|s[1]>0)
	{
		sum=s[0]|s[1];	
		cout<<sum-38;
		return 0;
	}
	else
	{
		cout<<sum-43;
	}
	return 0;
 } 
