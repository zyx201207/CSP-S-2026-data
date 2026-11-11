#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[500005];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<"1 ";
	for(int i=0;i<m;i++)
	{
	    cout<<a[i]<<" ";	
	}
	return 0;
}
