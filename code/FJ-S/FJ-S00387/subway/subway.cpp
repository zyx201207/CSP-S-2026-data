#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// BUSTER
inline int qread()
{
	char c=getchar();
	int x=0,f=1;
	for(;!isdigit(c);c=getchar())if(c=='-')f*=-1;
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	return x*f;
}
vector<vector<int>>w;
vector<int>tim,tp2,tp3;
int c,n,m,d,q,a,b;
void dfs()
{
	for(int p=0;p<m;p++)
	{
		for(int i=p+1;i<m;i++)
		{
			if(w[p][i]!=1e9)
			{
				for(int o=i+1;o<m;o++)
				{
					w[o][p]=w[p][o]=min(w[p][i]+w[i][o],w[p][o]);
				}
			}
		}	
	}	
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=qread();n=qread();m=qread();d=qread();q=qread();
	w.resize(m,vector<int>(m,1e9));
	tim.resize(m);
	for(int p=0;p<m;p++)tim[p]=qread();
	for(int p=0;p<n;p++)
	{
		a=qread();
		tp2.clear();
		tp3.clear();
		tp2.resize(d);
		tp3.resize(d);
		for(int i=0;i<a;i++)
		{
			tp2[i]=qread()-1;
			tp3[i]=qread();
		}
		for(int i=0;i<a;i++)
		{
			for(int o=i+1;o<a;o++)
			{
				w[tp2[o]][tp2[i]]=tp3[o]+tp3[i];
				w[tp2[i]][tp2[o]]=tp3[o]+tp3[i];
			}
		}
	}
	dfs();
	for(int p=0;p<q;p++)
	{
		a=qread()-1;
		b=qread()-1;
		cout<<w[a][b]+tim[a]+tim[b]<<endl;
	}
	return 0;
}
