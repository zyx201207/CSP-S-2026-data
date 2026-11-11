#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int n,x,l,r,ans=0;
char q,a[N];
string s,s1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>q;
		if(x%2==0)
		{
			for(int j=1;j<=x/2;j++)
			{
				s1[i]=q;
			}
		}
		else if(x==1) s1[n/2+1]=q;
		else 
		{
			for(int j=1;j<=x/2;j++)
			{
				s1[i]=q;
			}
		}
		for(int j=1;j<=x;j++)
		{
			s+=q;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(s[i]!=s1[i]) ans++;
	}
	cout<<ans;
	return 0;
} 
//3
//2 a
//2 b
//1 c
//2 
//2 a
//3 a


