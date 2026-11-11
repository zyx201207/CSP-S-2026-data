//24
#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[5005],b[5005][5005],l[5005][5005],is[5005][5005];
queue<int> q;
void bfs(int num)
{
	q.push(num);
	while(!q.empty())
	{
		int s=q.front();
		q.pop();
		for(int i=s+1;i<=n;i++)
		{
			if(i!=s && b[s][i])
			{
				//cout<<num<<" "<<s<<" "<<i<<" "<<l[num][s]<<" "<<l[num][i]<<endl;
				if(l[num][s]+1==l[num][i] && l[num][i]!=1)
				{
					//cout<<"!"<<num<<" "<<s<<" "<<i<<" "<<l[num][s]<<" "<<l[num][i]<<endl;
					is[num][i]++;
					is[i][num]++;
				}
				if(l[num][s]+1<=l[num][i])
				{
					q.push(i);
					l[num][i]=l[num][s]+1;
				}
			}
		}
	}
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		memset(is,0,sizeof(is));
		memset(b,0,sizeof(b));
		memset(l,0x3f,sizeof(l));
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		for(int i=1;i<=n;i++)
		{
			l[i][i]=0;
			for(int j=1;j<=n;j++)
			{
				if(i!=j && abs(x[i]-x[j])<=d)
				{
					b[i][j]=1;
					l[i][j]=1;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			bfs(i);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j && is[i][j]==1)
					ans++;
		cout<<ans/2<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
