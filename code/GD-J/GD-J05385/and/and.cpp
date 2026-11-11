#include<bits/stdc++.h>
using namespace std;
struct q{
	string e;
	string c;
	int a;
}s[100001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int z=0;
	for(int i=0;i<n;i++)
	{
		cin>>s[i].a;
		int b=s[i].a;
		while(b!=0)
		{
			if(b%2==0)
			{
				s[z++].e='0';		
			}
			else
			{
				s[z++].e='1';
			}
			b/=2;
		}
		
	}
	for(int i=0;i<z;i++)
	{
		cout<<s[i].e;
	}
	return 0; 
}
