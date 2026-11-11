#include<bits/stdc++.h>
using namespace std;
struct node
{
	int fa=0;
	vector <int> son;
}l[5005];
int c,t,n,k,cnt;
bool isu[15];
bool isv[15];
void dfs(int p)
{
	for(auto i:l[p].son)
	{
		if(i==l[p].fa) continue;
		l[i].fa=p;
		dfs(i);
	}
	return ;
}
void check(int p)
{
	if(isu[p]&&(!isu[l[p].fa])) cnt++;
	for(auto i:l[p].son)
	{
		if(i==l[p].fa) continue;
		check(i);
	}
	return ;
}
int h(int p)
{
	isv[p]=true;
	if(isu[p]) return 0;
	int ret=1;
	for(auto i:l[p].son)
	{
		if(isv[i]) continue;
		ret=max(ret,h(i)+1);
	}
	return ret;
}
int g()
{
	cnt=0; check(1);
	if(cnt>2) return INT_MAX;
	int ccnt=0;
	for(int i=1;i<=n;i++) if(isu[i]) ccnt++;
	if(ccnt!=k) return INT_MAX;
	int ret=INT_MAX;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) isv[j]=false;
		isv[i]=true;
		ret=min(ret,h(i));
	}
	return ret;
}
int f(int p)
{
	if(p>n) return g();
	int ret=INT_MAX;
	isu[p]=false;
	ret=min(ret,f(p+1));
	isu[p]=true;
	ret=min(ret,f(p+1));
	return ret;
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			l[i].son.clear();
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			l[u].son.emplace_back(v);
			l[v].son.emplace_back(u);
		}
		dfs(1);
		cout<<f(1)<<endl;
	}
	return 0;
}
