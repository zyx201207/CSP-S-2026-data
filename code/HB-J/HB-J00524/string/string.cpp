#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long num;
	char ch;
}q[200005],q2[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin >> n;
	long long last=0,front=0;
	int lastn=n;
	long long last2=0,front2=0;
	int frontn=1;
	long long change1=0,change2=0;
	for(int i=1;i<=n;i++)
	{
		cin >> q[i].num >> q[i].ch;
		last+=q[i].num;
		last2+=q[i].num;
		q2[i].num=q[i].num;
		q2[i].ch=q[i].ch;
	}
	for(int i=1;i<=n;i++)
	{
		if(front+q[i].num>=last)
		{
			break;
		}
		front+=q[i].num;
		int up=q[i].num,ned=0;
		while(ned<up)
		{
			
			if(ned+q[lastn].num>=up)
			{
				if(q[i].ch!=q[lastn].ch)
				{
					change1+=(up-ned);
				}
				q[lastn].num-=(up-ned);
				break;
			}
			
			else
			{
				ned+=q[lastn].num;
				if(q[i].ch!=q[lastn].ch)
				{
					change1+=q[lastn].num;
				}
				lastn--;
			}
		}
		last-=up;
	}
	for(int i=n;i>=1;i--)
	{
		if(last2-q2[i].num<=front2)
		{
			break;
		}
		last2-=q2[i].num;
		int up=q2[i].num,ned=0;
		while(ned<up)
		{
			
			if(ned+q2[frontn].num>up)
			{
				if(q2[i].ch!=q2[frontn].ch)
				{
					change2+=(up-ned);
					
				}
				q2[frontn].num-=(up-ned);
				break;
			}
			else
			{
				ned+=q2[frontn].num;
				if(q2[i].ch!=q2[frontn].ch)
				{
					change2+=q2[frontn].num;
				}
				frontn++;
			}
		}
		front2+=up;
	}
	cout << min(change1,change2);
	return 0;
}
//O(n)
