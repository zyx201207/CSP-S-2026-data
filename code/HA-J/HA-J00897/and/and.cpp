#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("r","and.in",stdin);
	freopen("w","and.out",stdout);
	int n,m,iiiii=0;
	cin>>n>>m;
	int h;
	cin>>h;
	iiiii=max(iiiii,h);
	int p=h;
	for(int i=1;i<n;i++)
	{
		cin>>h;
		p=p&h;
		iiiii=max(iiiii,h);
	}
	if(m==1)
	{
		cout<<iiiii;
	}
	else
	{
		cout<<p;
	}
}
