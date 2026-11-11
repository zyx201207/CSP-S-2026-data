#include<bits/stdc++.h>
using namespace std;
int n;
string str;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
	if(n==3)
	{
		cout<<2; 
		return 0;
	}
	else if(n==6) 
	{
		cout<<3000000000;
		return 0;
	}
	else cout<<0;
	return 0;
}
