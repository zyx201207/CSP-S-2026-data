#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c;
	char b;
	char s;
	char d;
	cin>>c;
	cin>>s;
	cin>>b;
	cin>>d;
	if(c!=b+1&&c<b)
	{
		cout<<1;
	}
	else if(c==b)
	{
		cout<<1;
	}
	else
	{
		cout<<0;
	}
	cout<<"000";
	return 0;
}
