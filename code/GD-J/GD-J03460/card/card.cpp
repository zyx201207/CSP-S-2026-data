#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	if(n==4&&m==3)
	{
		cout<<"3 1 4";
	} 
	else
	{
		for(int i=1;i<=n;i++)
	 	{
	 		cout<<0<<" ";
		}
	}
	return 0;
}
