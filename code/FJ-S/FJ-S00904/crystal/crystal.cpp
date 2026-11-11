#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,b,m=0,s=1,d=0,t=0;
	bool f=1;
	cin>>a>>b;
	long long n[a],c[a];
	for(long long i=0;i<a;i++)
	{
		cin>>n[i];
}
	sort(n+0,n+a);
	m=a/2+a%2;
	for(long long i=0;i<m-1;i++)
	{
		if(n[m-1]-n[m-2-i]<n[m+i]-n[m-1])
		{
			if(b>=n[m-1]-n[m-2-i])
		{
			b=b-(n[m-1]-n[m-2-i]);
			n[m-2-i]=n[m-1];
			s++;
		}
		}
		else
		{
			if(b>=n[m+i]-n[m-1])
		{
			b=b-(n[m+i]-n[m-1]);
			n[m-1]=n[m+i];
			s++;
		}
		}
}
	cout<<s;
	return 0;
}
