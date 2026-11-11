#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
long long n,s,l,z,t;
struct str
{
	long long a;
	char c;
}q[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i].a>>q[i].c;
	}
	l=min(q[1].a,q[n].a);
	if(q[1].a>q[n].a)t=1;
	else t=0;
	for(int i=1,j=n;i<=(n+1)/2&&j>=(n+1)/2;)
	{
		if(q[i].c!=q[j].c)
		  s+=l;
		if(t==1)
		{
			j--;
			l=q[i].a-l;
			if(l>q[j].a)
			  t=1,l=q[j].a,q[i].a-=l;
			else
			  t=0;
		}
		else
		{
			i++;
			l=q[j].a-l;
			if(l>q[i].a)
			  t=0,l=q[i].a,q[j].a-=l;
			else
			  t=1;
		}
	}
	cout<<s;
	return 0;
}
