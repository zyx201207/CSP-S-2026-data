#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,k=0,cnt=0;
	int t[10000005];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>t[i];
		k+=t[i];
	}
	for(int i=0;i<n;i++)
	{
		if(t[i]>k/n)
		{
			cnt++;
		}
	 } 
	 cout<<cnt;
	return 0;
 } 
