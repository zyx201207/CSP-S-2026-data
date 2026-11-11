#include<bits/stdc++.h>
using namespace std;
struct st
{
	long long a;
	char c;
}q[200020];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,s=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i].a>>q[i].c;
		s+=q[i].a;
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	if(n==2)
	{
		if(q[1].c==q[2].c)
		{
			cout<<0;
			return 0;
		}
		if(s/2>=q[1].a)
		{
			cout<<q[1].a;
		}
		else
		{
			cout<<q[2].a;
		}
	}
	return 0;
} 
