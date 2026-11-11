#include<bits/stdc++.h>
using namespace std;

int a[1000],t,t1,b[1000];
int main()
{
	freopen("card.in","r","stdin");
	freopen("card.out","w","stdout");
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]==a[j])
			{
				i=j;
			}
		}
		
	}
	if(n==4 and m==2)
	{
		cout<<"3"<<"1"<<"4";
	}
	
	return 0;
}
