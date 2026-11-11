#include<bits/stdc++.h>
#define int long long
#define pa pair<int,int>
#define v first
#define w second
using namespace std;
const int oo=0x7fffffffffffll;
const int M=5*1e5+5;
const int N=505;
int c,n,m,d,q;
int x[M],f[N][N];
vector<pa >g[M];
pa mk(int a,int b){return make_pair(a,b);}
int read(){
	int res=0;
	char ch;
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<1)+(res<<3)+ch-'0',ch=getchar();
	return res;
}
void write(int x){
    if(x>=10)write(x/10);
    putchar('0'+x%10);
    return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int k,a,s,t;
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++)x[i]=read();
	for(int i=1;i<=n;i++){
		k=read();
		for(int j=1;j<=k;j++)a=read(),t=read(),g[a].push_back(mk(i,t));
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)f[i][j]=oo;
	for(int i=1;i<=n;i++)f[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<g[i].size();j++){
			for(int k=0;k<g[i].size();k++){
				if(j==k)continue;
				f[g[i][j].v][g[i][k].v]=min(f[g[i][j].v][g[i][k].v],g[i][j].w+g[i][k].w);
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	while(q--){
        int ans=oo;
		s=read(),t=read();
		for(int i=0;i<g[s].size();i++)
			for(int j=0;j<g[t].size();j++)
				ans=min(ans,g[s][i].w+g[t][j].w+f[g[s][i].v][g[t][j].v]);
		write(ans+x[s]+x[t]),printf("\n");
	}
	return 0;
}
