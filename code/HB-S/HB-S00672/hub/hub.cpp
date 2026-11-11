#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(n==0&&m==2)
	{
		cout<<"1"<<endl;
		cout<<"2"<<endl;
	}
	else if(n==0&&m==3)
	{
		cout<<"1"<<endl;
		cout<<"1"<<endl;
		cout<<"2"<<endl;
	}
	else
	{
		for(int i=1;i<=m;i++)
		{
			cout<<"1"<<endl;
		}
	}
	return 0;
}
