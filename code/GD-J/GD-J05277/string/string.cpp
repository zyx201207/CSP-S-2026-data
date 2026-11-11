#include<bits/stdc++.h>
using namespace std;
struct p
{
	long long a;
	char c;
}q[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>q[i].a>>q[i].c;
	}
	long long ans=0;
	int k=n;
	int v=1;
	while(k>=v)
	{
		if(v==k)
		{
			break;
		}
		if(q[v].c==q[k].c)
		{
			if(q[v].a>q[k].a)
			{
				q[v].a-=q[k].a;
				q[k].a=0;
				k--;
			}
			else if(q[v].a==q[k].a)
			{
				q[v].a=0;
				q[k].a=0;
				k--;
				v++;
			}
			else
			{
				q[k].a-=q[v].a;
				q[v].a=0;
				v++;
			}
		}
		else
		{
			if(q[v].a>q[k].a)
			{
				ans+=q[v].a-q[k].a;
				q[v].a-=q[k].a;
				q[k].a=0;
				k--;
			}
			else if(q[v].a==q[k].a)
			{
				ans+=q[v].a;
				q[v].a=0;
				q[k].a=0;
				k--;
				v++;
			}
			else
			{
				ans+=q[k].a-q[v].a;
				q[k].a-=q[v].a;
				q[v].a=0;
				v++;
			}
		}
	}
	cout<<ans;
	return 0;
} 
