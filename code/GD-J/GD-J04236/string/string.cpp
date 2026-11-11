#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,sum=0,sum1=0,sumj=0;
bool flag=false;
struct node
{
	int s;
	char c;
}a[200005];
stack<node> stk;
queue<node> que;
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].s>>a[i].c;
		sum+=a[i].s;
	}
	for(int i=1;i<=n;i++)
	{
		if(flag==false)
		{
			sum1+=a[i].s;
		    que.push({a[i].s,a[i].c});
		    if(sum1+a[i+1].s>=sum/2)
		    {
		    	que.push({sum/2-sum1,a[i+1].c});
		    	if(sum1+a[i+1].s>sum/2)
	    		{
	    		    stk.push({sum1+a[i+1].s-sum/2,a[i+1].c});
		    	}
		    	flag=true;
		    }
		}
		else
		{
			stk.push({a[i].s,a[i].c});
		}
	}
	while(stk.empty()==false&&que.empty()==false)
	{
		if(stk.top().c!=que.front().c)
		{
			sumj+=min(stk.top().s,que.front().s);
		}
		if(stk.top().s<que.front().s)
		{
			que.front().s-=stk.top().s;
			stk.pop();
		}
		else if(stk.top().s>que.front().s)
		{
			stk.top().s-=que.front().s;
			que.pop();
		}
		else
		{
			stk.pop();
			que.pop();
		}
	}
	cout<<sumj<<endl;
	return 0;
}
