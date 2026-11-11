#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],x[100005],y[100005],mina;
vector<int>a[505],t[505],b[500005];
void ok1(int x,int tn,int fa,int y,int s)
{
	int t1=0;
	if(tn!=-1) 
	{
		for(int i=0;i<(int)a[tn].size();i++)
		{
			if(a[tn][i]==x)
			{
				if(x!=y && i<a[tn].size()-1 && a[tn][i+1]!=fa) ok1(a[tn][i+1],tn,x,y,s);
				if(i!=0)
				{
					if(x!=y && a[tn][i-1]!=fa) ok1(a[tn][i-1],tn,x,y,s);
				}
				t1=t[tn][i];	
				break;	
			} 
		}
	}
	if(x==y)
	{
		mina=min(mina,s+t1);
		return ;
	}
	for(int i=0;i<(int)b[x].size();i++)
	{
		if(b[x][i]==tn) continue;
		for(int j=0;j<(int)a[b[x][i]].size();j++)
		{
			if(a[b[x][i]][j]==x)
			{
				int ts=s;
				if(tn!=-1) ts+=t1;
				ts+=t[b[x][i]][j];
				if(j<a[b[x][i]].size()-1)ok1(a[b[x][i]][j+1],b[x][i],x,y,ts);
				if(j>0)ok1(a[b[x][i]][j-1],b[x][i],x,y,ts);
			}
		}
	} 
}
void ok2(int x,int y,int s)
{
	int t1=0,t2=0;
	for(int i=0;i<(int)a[1].size();i++)
	{
		if(a[1][i]==x) 
		{
			t1=t[1][i];
			continue;
		}
		if(a[1][i]==y) t2=t[1][i];
	}
	if(t1!=0 && t2!=0) mina=min(mina,t1+t2);
	int t3=0,t4=0;
	for(int i=0;i<(int)a[2].size();i++)
	{
		if(a[2][i]==x) 
		{
			t3=t[2][i];
			continue;
		}
		if(a[2][i]==y) t4=t[2][i];
	}
	if(t3!=0 && t4!=0) mina=min(mina,t3+t4);
	for(int i=0;i<(int)a[1].size();i++)
	{
		if(a[1][i]==y || a[1][i]==x) continue;
		if(b[a[1][i]].size()==2) 
		{
			int t5=0;
			for(int j=0;j<(int)a[2].size();j++)
			{
				if(a[2][j]==a[1][i]) t5=t[2][j]; 
			}
			mina=min(mina,t1+t4+t[1][i]+t5);
		}
	}
	for(int i=0;i<(int)a[1].size();i++)
	{
		if(a[2][i]==y || a[2][i]==x) continue;
		if(b[a[2][i]].size()==2) 
		{
			int t5=0;
			for(int j=0;j<(int)a[1].size();j++)
			{
				if(a[1][j]==a[1][i]) t5=t[1][j]; 
			}
			mina=min(mina,t3+t2+t[2][i]+t5);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k[i]);
		for(int j=0;j<k[i];j++)
		{
			int t1,t2;
			scanf("%d%d",&t1,&t2);
			b[t1].push_back(i);
			a[i].push_back(t1);
			t[i].push_back(t2);
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	if(c>=1 && c<=15)
	{
		for(int i=1;i<=q;i++)
		{
			mina=1e9;
			ok1(x[i],-1,-1,y[i],0);
			cout<<mina+w[x[i]]+w[y[i]]<<'\n';
		}
	} 
	else if(c>=20 && c<=21)
	{
		for(int i=1;i<=q;i++)
		{
			mina=1e9;
			ok2(x[i],y[i],0);
			cout<<mina<<'\n';
		}
	}
	return 0;
}

