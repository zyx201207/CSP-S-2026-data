#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out"," w",stdout);
	int n=0,a=0;
	cin>>n;
	string s,q,f,b;
	for(int i=0;i<n;i++)
	{
		int a=0;
		cin>>a;
		cin>>s;
		string z=s;
		for(int j=1;j<a;j++)
		{
			s=s+z;
		}
		q+=s;
	}
	for(int i=0;i<q.size()/2;i++)
	{
		f[i]=q[i];
	}
	for(int i=q.size()-1;i>q.size()/2;i--)
	{
		b[i]=q[i];
	}
	for(int i=0;i<q.size()/2;i++)
	{
		for(int j=q.size()-1;j>q.size()/2;j--)
	if(f[i]!=b[j])
		
		
		a++;
	}
	cout<<a/2;
return 0;

}  
