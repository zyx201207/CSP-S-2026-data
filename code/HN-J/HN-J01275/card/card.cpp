#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5,INF=0x3f3f3f3f;
deque<int> stk;
vector<int> a;
int n,m;
int c[N],cnt[M];
int find(int x,deque<int> y)
{
	int p=INF;
	for(int i=0;i<y.size();i++)
	{
		if(y[i]==x) p=min(p,i);
	}
	return p;
}
void play(int u)
{
	stk.clear();
	a.clear();
	for(int i=u;i<=n;i++)
	{
		a.push_back(c[i]);
		stk.push_back(c[i]);
	}	
	int len=a.size();
	for(int i=0;i<len;i++)
	{
		int tgt=a[i];
		int pos=find(tgt,stk);
		if(pos!=INF) while(stk.size()!=pos) stk.pop_back();	
		stk.push_back(tgt);	
	}
	for(int i=0;i<stk.size();i++)
	{
		cnt[stk[i]]++;
	}
} 	
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];	
	}
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=n;i++)
	{
		play(i);
	}
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<' ';
	}
	cout<<'\n';
	return 0;
}
