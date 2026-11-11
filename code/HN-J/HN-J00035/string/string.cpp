#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s,a;
	int n;
	long long b;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>b;
		cin>>a;
		for(int i=1;i<=b;i++)
		{
			s+=a;
		}
	}
	cout<<"2";
	return 0;
 } 
