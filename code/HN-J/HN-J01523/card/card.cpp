#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	vector<int> b;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	} 
	for(int i=0;i<n;i++)
	{
		if(a[i+1]!=a[i]) 
		{
			b.push_back(i+1);
		}
	}
	for(int i=0;i<m;i++) cout<<b[i]<<' ';
	return 0;
}
