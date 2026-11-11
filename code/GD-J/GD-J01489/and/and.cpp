#include<bits/stdc++.h>
using namespace std;
int ans(int a,int b)
{
	if(a==b)
	{
		return a;
	}
	if(a<b)
	{
		return a;
	}
	if(a>b)
	{
		return b;
	}
};
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,b;
	cin>>a>>b;
	cout<<ans(a,b);
	return 0;
 } 
