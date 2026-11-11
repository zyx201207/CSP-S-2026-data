#include<bits/stdc++.h>
using namespace std;
int n,m,len;
long long ans,a[200010];
bool b[200010][50];
queue<int> q;
int read()
{
	int ans=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') ans=ans*10+c-'0',c=getchar();
	return ans;
}
void fj(int x)
{
	for(int i=0;a[x];i++)
	{
		if(a[x]&1) b[x][i]=1;
		a[x]>>=1;
	}
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) 
	{
		a[i]=read();
		fj(i);
		q.push(i);
	}
	len=n;
	int k=pow(2,29);
	for(int i=29;i>=0;i--,k/=2)
	{
		int cnt=0;
		for(int j=1;j<=len;j++)
		{
			if(b[q.front()][i]==1) cnt++;
			q.push(q.front());
			q.pop();
		}
		if(cnt>=m)
		{
			ans+=k;
			for(int j=1;j<=len;j++)
			{
				if(b[q.front()][i]==1) q.push(q.front());
				q.pop();
			}
			len=cnt;
		}
	}
	cout<<ans;
	return 0;
}
