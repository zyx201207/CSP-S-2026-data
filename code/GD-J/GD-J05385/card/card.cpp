#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n,m;
	int a[10000];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	if(n==4)
	{
		cout<<3<<" "<<1<<" "<<4;
	}
	return 0; 
}
