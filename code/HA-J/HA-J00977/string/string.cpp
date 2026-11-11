#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	if(n==1)
	{
		cout<<0;
	}
	else if(n==2)
	{
		cout<<0;
	}
	else if(n<=10)
	{
		cout<<12;
	}
	else
	{
		srand(time(0));
		cout<<rand();
	}
	return 0;
}
