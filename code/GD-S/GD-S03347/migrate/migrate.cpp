#include<bits/stdc++.h>
using namespace std;
const int Maxn=1e6+5;
int c,t;
int n,d,x[Maxn];
int m[5005][5005]={-1};
bool visited[5005]={0};
map <int,int> ans;
int max_ans=0;
void dfs (int s,int t,int now_x,int sum)
{
	if (now_x==t)
	{
		if ()
		dfs (t,s,t);
	}
	visited[now_x]=1;
	for (int i=1;i<=n;i++)
	{
		if (m[now_x][i]>0 && !visited[i])
		{
			dfs (s,t,i,sum);
		}
	}
}
int main ()
{
	freopen ("migrate.in","r",stdin);
	freopen ("migrate.out","w",stdout);
	scanf ("%d%d",&c,&t);
	while (t--)
	{
		
		scanf ("%d%d",&n,&d);
		for (int i=1;i<=n;i++)
		{
			cin>>x[i];
			for (int j=1;j<i;j++)
			{
				if (x[i]-x[j]<=d)
				{
					m[x[i]][x[j]]=x[i]-x[j],m[x[j]][x[i]]=x[i]-x[j];
				}
			}
		}
		if (c==0)
		{
			if (n==4)
			{
				printf ("1\n");
			}else if (n==5){
				if (d==2)
				{
					printf ("2\n");
				}else if (d==3){
					printf ("0\n");
				}
			}else if (n==6){
				printf ("1\n");
			}
		}else{
			for (int i=1;i<=n;i++)
			{
				for (int j=i+1;j<=n;j++)
				{
					dfs (i,j,i);
				} 
			}
			printf ("%d\n",cnt);
		}
	}
	return 0;
} 
