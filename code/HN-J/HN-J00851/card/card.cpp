#include<bits/stdc++.h>
using namespace std;
char a,b;
int n,m,s;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s;	
	}
	for(int i=1;i<=m;i++)
	{
		cout<<s-1+m<<" ";
	}
	
	return 0;
} 
