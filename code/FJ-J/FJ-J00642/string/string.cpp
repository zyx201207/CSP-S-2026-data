#include<bits/stdc++.h>
using namespace std;
struct node
{
	long long len;
	char a;
}p[200005];
int n,k=1;
long long cnt;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		char ch;
		cin>>x>>ch;
		if(ch==p[k-1].a)
		{
			p[k-1].len+=x;
		}
		else
		{
			p[k].a=ch;
			p[k].len=x;
			k++;
		}
	}
	int l=1,r=k-1;
	while(l<=r)
	{
		if(p[l].a!=p[r].a)
		{
			if(p[l].len>p[r].len)
			{
				cnt+=p[r].len;
				p[l].len-=p[r].len;
				r--;
			}
			else if(p[l].len<p[r].len)
			{
				cnt+=p[l].len;
				p[r].len-=p[l].len;
				l++;
			}
			else
			{
				cnt+=p[l].len;
				l++;
				r--;
			}
		}
		else
		{
			if(p[l].len>p[r].len)
			{
				p[l].len-=p[r].len;
				r--;
			}
			else if(p[l].len<p[r].len)
			{
				p[r].len-=p[l].len;
				l++;
			}
			else
			{
				l++;
				r--;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}
