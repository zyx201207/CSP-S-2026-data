#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,m,a[N],dp[N]={0},vis[N];
string c,d;
string q,w,q2,w2;
int awy(int l,int r)
{
	int cnd=1;
	int ans=0,jishu=1;
	while(cnd<=l)
	{
		cnd*=2;
	}
	while(l!=0)
	{
		cnd/=2;
		int i=l/cnd;
		if(i==1)
		{
			q+='1';
		}
		else
		{
			q+='0';
		}
		if(l%cnd==0)
		{
			int fie=cnd,wei=0;
			while(fie!=1)
			{
				fie/=2;
				wei++;
			}
			for(int i=1;i<=wei;i++)
			{
				q+='0';
			}
		}
		l%=cnd;
	}
	cnd=1;
	while(cnd<=r)
	{
		cnd*=2;
	}
	while(r!=0)
	{
		cnd/=2;
		int i=r/cnd;
		if(i==1)
		{
			w+='1';
		}
		else
		{
			w+='0';
		}
		if(r%cnd==0)
		{
			int fie=cnd,wei=0;
			while(fie!=1)
			{
				fie/=2;
				wei++;
			}
			for(int i=1;i<=wei;i++)
			{
				w+='0';
			}
		}
		r%=cnd;
	}
	cnd=1;
	if(q.size()<w.size())
	{
		for(int i=1;i<=w.size()-q.size();i++)
		{
			q2+='0';
		}
	}
	else
	{
		for(int i=1;i<=q.size()-w.size();i++)
		{
			w2+='0';
		}
	}
	q2+=q;
	w2+=w;
	int len=max(q2.size()-1,w2.size()-1);
	int as=0x3f3f3f3f;
	for(int i=0;i<=len;i++)
	{
		if(q2[i]=='1' and i<=as)
		{
			as=i;
		}
		if(w2[i]=='1' and i<=as)
		{
			as=i;
		}
	}
	string q3,w3;
	for(int i=as;i<=len;i++)
	{
		q3+=q2[i];
		w3+=w2[i]; 
	}
	len=max(q3.size()-1,w3.size()-1);
	for(int i=len;i>=0;i--)
	{
		if((q3[i]=='1' and w3[i]=='1'))
		{
			ans+=jishu;
		}
		jishu*=2;
	}
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	memset(dp+1+n,0,0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=m;i++)
	{
		dp[i]=a[i]+dp[i-1];
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(j==k)
				{
					continue;
				}
				dp[i]=max(dp[i-1],awy(a[k],a[j]));
			}
		}
	}
	cout<<dp[m];
}
