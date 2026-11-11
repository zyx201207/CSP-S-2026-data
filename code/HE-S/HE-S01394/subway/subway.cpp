#include<bits/stdc++.h>
using namespace std;
struct S
{
	string e1,e2;
	int s;
};
int c,n,m,d,q,w[50005],at[505][20005],x,y,t=1,ans,minn;
S re[500005];
bool vis[500005];
void dfs(string now,string ex,int rec)
{
	if(now==ex)
	{
		if(minn==-1||minn>rec)
		{
			minn=rec;
		}
		return ;
	}
	for(int i=1;i<t;i++)
	{
		if(vis[i])
		{
			continue;
		}
		if(re[i].e1==now)
		{
			vis[i]=true;
			dfs(re[i].e2,ex,rec+re[i].s);
		}
		if(re[i].e2==now)
		{
			vis[i]=true;
			dfs(re[i].e1,ex,rec+re[i].s);
		}
	}
	return ;
}
string f(int a)
{
	string b;
	while(a)
	{
		int w=a%10;
		if(a==0)
		{
			b+="0";
		}
		if(a==1)
		{
			b+="1";
		}
		if(a==2)
		{
			b+="2";
		}
		if(a==3)
		{
			b+="3";
		}
		if(a==4)
		{
			b+="4";
		}
		if(a==5)
		{
			b+="5";
		}
		if(a==6)
		{
			b+="6";
		}
		if(a==7)
		{
			b+="7";
		}
		if(a==8)
		{
			b+="8";
		}
		if(a==9)
		{
			b+="9";
		}
		a/=10;
	}
	int len=b.size();
	string c="";
	for(int i=len-1;i>=0;i--)
	{
		c+=b[i];
	}
	return c;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
		re[t].e1="w"+f(i);
		re[t].e2="t"+f(i);
		re[t++].s=w[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>at[i][0];
		for(int j=1;j<=at[i][0];j++)
		{
			cin>>at[i][j*2-1]>>at[i][j*2];
			re[t].e1="t"+f(at[i][2*j-1]);
			re[t].e2="z"+f(at[i][2*j-1])+","+f(+i);
			re[t++].s=at[i][j*2];
			if(j>1)
			{
				re[t].e1="z"+f(at[i][2*j-3])+","+f(i);
				re[t].e2="z"+f(at[i][2*j-1])+","+f(i);
				re[t++].s=0;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		ans=0;
		minn=-1;
		dfs("w"+f(x),"w"+f(y),ans);
		cout<<minn<<endl;
		for(int i=1;i<t;i++)
		{
			vis[i]=false;
		}
	}
	return 0;
}
