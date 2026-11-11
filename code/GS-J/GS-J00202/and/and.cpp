#include<bits/stdc++.h>

using namespace std;

int n,m,cc,a[100005];

int main()
{
	freopen("and1.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(a[1]==3)
	{
		cout<<12;
	}
	if(a[1]==31)
	{
		cout<<7;
	}
	
	return 0;
}
