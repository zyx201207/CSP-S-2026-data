#include<bits/stdc++.h>
using namespace std;
const int MAXM=3*1e5+10;
const int MAXN=5*1e5+10;
struct node{
	int pre,next;
	int x;
}l[MAXN];
int n,m;
int a[MAXN];
int c[MAXM];
bool f[MAXM];
int id[MAXM];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		id[a[i]]=min(i,id[a[i]]);
	}
	c[a[n]]=1;
	l[n].pre=n-1;
	l[n].next=-1;
	l[n].x=a[n];
	int t=0;
	for(int k=1;k<n;k++)
	{
		memset(f,0,sizeof(f));
		l[k].pre=-1;
		l[k].next=k+1;
		l[k].x=a[k];
		for(int i=k+1;i<n;i++)
		{
			l[i].pre=i-1;
			l[i].next=i+1;
			l[i].x=a[i];
		}
		for(int i=k;i<=n;i++)
		{
			if(!f[a[i]])
				f[a[i]]=1;
			else
			{
				for(int j=id[a[i]];j<=t;j++)
				{
					f[l[j].x]=0;
					t--;	
				}
				l[l[id[a[i]]].pre].next=i;
				l[i].pre=l[id[a[i]]].pre;
				l[i].next=-1;
				f[a[i]]=1;
				id[a[i]]=i;
			}
			t++;
		}
		for(int i=1;i<=m;i++)
		{
			if(f[i])
				c[i]++;	
		}
	}
	for(int i=1;i<=m;i++)
		cout<<c[i]<<' ';
	return 0;
}
