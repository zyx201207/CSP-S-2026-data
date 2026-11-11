#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c=0,cnt[500005];
bool v[300005];
queue<int> q;
queue<int> q1;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	while(c<=n)
	{
		c++;
		for(int i=c;i<=n;i++)
		{
			if(!v[a[i]]) q.push(a[i]),v[a[i]]=1;
			else {
				while(!q.empty()&&q.front()!=a[i])
				{
					q1.push(q.front());
					q.pop();
				}
				while(!q.empty()) q.pop();
				while(!q1.empty()) q.push(q1.front()),q1.pop();
				q.push(a[i]);
			}
		}
		while(!q.empty()) cnt[q.front()]++,q.pop();
		memset(v,0,sizeof v);
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0; 
}
