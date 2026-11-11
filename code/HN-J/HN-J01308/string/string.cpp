#include <bits/stdc++.h>
using namespace std;
int main()
{	
	int n;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	cin>>n;
	string a;
	int y=1;
	for(int i=0;i<n;i++)
	{
		char s;
		int x;
		cin>>x>>s;
		while(x>0)
		{
			a[y]=s;
			y++;
			x--;
		}
	}
	y--;
	int n1=y/2+1,sum=0;
	for(int i=1;i<=n1;i++)
	{
		if(a[y+1-i]!=a[i]) sum++;
	}
	cout<<sum;
	return 0; 	
} 
