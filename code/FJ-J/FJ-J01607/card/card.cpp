#include<bits/stdc++.h>
using namespace std;
int a[500001],vis[500001],g,ggg[500001];
struct st{
	int x,y;
}s[500001],s1[500001];
bool bo(st a,st b)
{
	if(a.x<b.x)
		return true;
	if(a.x==b.x)
		return a.y<b.y;
	return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ggg[a[i]]+=i;
	}
	for(int j=1;j<=n;j++)
	{
		if(vis[a[j]]!=0)
		{
			s[++g].x=vis[a[j]];
			s[g].y=j-1;//
		}vis[a[j]]=j;
	}
	sort(s+1,s+1+g,bo);
	for(int i=1;i<=n;i++)
	{
		int gg=0,my=0;
		for(int j=1;j<=g;j++)
		{
			s1[j].x=s[j].x;
			s1[j].y=s[j].y;
		}
		for(int j=1;j<=g;j++)
		{
			if(s1[j].x<i)
			{
				gg=j+1;
				continue;
			}
			if(/*s[j-1].x>=i&&*/my>=s1[j].x)
			{
				s1[j].y=s1[i].x;
			}	
			if(s1[j-1].x>=i&&s1[j-1].x==s1[j].x)
			{
				s1[j-1].y=s1[j-1].x;
			}				
//			}

//			if(s[j-1].x>=i&&s[j-1].y<=s[j].y)
//			{
//				s[j].x=s[i].y;
//				s[j-1].y=s[i].y;
//			}
			if(my<=s[j].y&&my>=s[i].x)
			{
				my=s1[i].y;
			}
		}
		for(int j=gg;j<=g;j++)
		{
			for(int k=s[j].x;k<=s[j].y;k++)
			{
				ggg[a[k]]--;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{	
		cout<<ggg[i]<<" ";
	}

	return 0;
}

