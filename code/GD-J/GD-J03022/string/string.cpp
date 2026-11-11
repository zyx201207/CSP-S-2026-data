#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005],cnt=0,ans=0,x,m=0;
char c[200005];
queue<pair<int,long long>> q;
queue<pair<int,long long>> q1;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	if(cnt%2==1) m=1;
	cnt--;
	cnt/=2; 
	for(int i=1;i<=n;i++)
	{
		if(cnt<a[i]) 
		{
			x=i;
			if(cnt!=0) q.push({c[i]-'a',cnt});
			a[i]=a[i]-cnt-m;
			break;
		}
		cnt-=a[i];
		q.push({c[i]-'a',a[i]});
	} 
	for(int i=n;i>=x;i--)
	{
		q1.push({c[i]-'a',a[i]});
	}
	while(!q.empty()&&!q1.empty())
	{
		if(q.front().first==q1.front().first)
		{
			if(q.front().second==q1.front().second) q.pop(),q1.pop();
			if(q.front().second>q1.front().second) q.front().second-=q1.front().second,q1.pop();
			else q1.front().second-=q.front().second,q.pop();
		}
		else if(q.front().second==q1.front().second) ans+=q1.front().second,q.pop(),q1.pop(); 
		else if(q.front().second>q1.front().second) q.front().second-=q1.front().second,ans+=q1.front().second,q1.pop();
		else q1.front().second-=q.front().second,ans+=q.front().second,q.pop();
	}
	cout<<ans;
	return 0;
}
