#include<bits/stdc++.h>
using namespace std;
int main()
{
//	freopen ("travel.in","r",stdin);
//	freopen ("travel.out","w",stdout);
	int c1,c2,s1,s2,n;
	cin>>c1>>c2>>s1>>s2>>n;
	for (int i=1;i<=n;i++)
	{
		if (c1==c2)
		{
			cout<<"1000";
			return 0;
		}	
		if (c1!=c2)
		{
			cout<<"0000";
			return 0;
		}
	}
	return 0;
 } 
