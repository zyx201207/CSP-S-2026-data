#include<bits/stdc++.h>
using namespace std;
const int dd=5e5+5;
const int dd2=3e5+5;
int n,m;
int a[dd];
int fa[dd2];
int cnt[dd2];
vector<int> son[dd2];
int read()
{
	int x=0;int f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0){
		putchar('-');
		write(-x);
		return;
	}
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}
void dfs(int root)
{
	for(int i:son[root]){
		dfs(i);
		cnt[root]+=cnt[i];
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	cnt[a[n]]=1;
	for(int i=n-1;i>=1;i--){
		if(cnt[a[i]]==0) son[a[i+1]].push_back(a[i]);
		cnt[a[i]]++;
	}
	dfs(a[n]);
	for(int i=1;i<=m;i++) write(cnt[i]),putchar(' ');
	return 0;
}
