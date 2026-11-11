#include<bits/stdc++.h>
using namespace std;
struct letter
{
	long long num;
	char l;
}a[200005];
string s;
long long n,len;
queue<letter> q1,q2;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i = 1;i<=n;i++)
	{
		long long x;
		cin>>x>>a[i].l;
		a[i].num=x;
		len+=x;
	}
	long long mid=0;
	for(long long i = 1;i<=n;i++)
	{
		mid+=a[i].num;
		if(mid>len/2)
		{
			mid=i;
			break;
		}
	}
	long long l1=0,l2=0;
	for(long long i = 1;i<=mid;i++)
	{
		if(i==mid)
		{
			letter x=a[i];
			x.num=len/2-l1;
			q1.push(x);
			break;
		}
		l1+=a[i].num;
		q1.push(a[i]);
	}
	cout<<endl;
	for(long long i = n;i>=mid;i--)
	{
		if(i==mid)
		{
			letter x=a[i];
			x.num=len/2-l2;
			q2.push(x);
			break;
		}
		l2+=a[i].num;
		q2.push(a[i]);
	}
	long long c=0;
	while(!q1.empty() && !q2.empty())
	{
		if(q1.front().l==q2.front().l)
		{
			if(q1.front().num>=q2.front().num)
			{
				q1.front().num-=q2.front().num;
				q2.front().num=0;
			}
			else
			{
				q2.front().num-=q1.front().num;
				q1.front().num=0;
			}
		}
		else
		{
			if(q1.front().num>=q2.front().num)
			{
				q1.front().num-=q2.front().num;
				c+=q2.front().num;
				q2.front().num=0;
			}
			else
			{
				q2.front().num-=q1.front().num;
				c+=q1.front().num;
				q1.front().num=0;
			}
		}
		if(q1.front().num==0)
		{
			q1.pop();
		}
		if(q2.front().num==0)
		{
			q2.pop();
		}
	}
	cout<<c;
	return 0;
}
