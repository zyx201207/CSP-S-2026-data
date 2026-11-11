#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s1="";
	cin>>n;
	if(n==1)
	{
		cout<<"0";
	}
	else if(n==2)
	{
		int a,b;
		string a1,b1;
		cin>>a>>a1;
		cin>>b>>b1;
		if(a1==b1)
		{
			cout<<"0";
		}
		else
		{
			cout<<min(a,b);
		}
	}
	return 0;
}
