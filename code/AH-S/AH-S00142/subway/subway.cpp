#include<bits/stdc++.h>
#define int long long
using namespace std;
const int dd=5e5+5;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0'){
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
int cc,n,m,d,q;
int w[dd],sz[505];
vector<int> a[505],t[505];
vector<int> g[dd];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cc=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	for(int i=1;i<=n;i++){
		sz[i]=read();
		for(int j=1;j<=sz[i];j++){
			int x,y;x=read(),y=read();
			a[i].push_back(x);
			t[i].push_back(y);
			g[a[i][a[i].size()-2]].push_back(x);
		}
	}
	while(q--){
		int x,y;x=read(),y=read();
		write((x-y+1)*t[x][t[x].size()-1]);
		putchar('\n');
	}
	return 0;
}
