#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
const int M=5e5+10;
int w[N],k[500],t[500][5000];
int r[500][5000];
int c,n,m,d,q;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){ x=x*10+(ch-'0'); ch=getchar();}
	return x*f;
}
int ans;
void dfs(int x,int s,int f,int num){
	if(num>=ans) return ;
	if(x==s&&!f){
		ans=min(ans,num);
		return ;
	}
	if(f==0){
		for(int i=1;i<=n;i++){
			if(!r[i][x]&&t[i][x]>0){
				r[i][x]=1;
				dfs(i,s,1,num+t[i][x]);
				r[i][x]=0;
			}
		}
	}else{
		for(int i=1;i<=d;i++){
			if(!r[x][i]&&t[x][i]>0){
				r[x][i]=1;
				dfs(i,s,0,num+t[x][i]);
				r[x][i]=0;
			}
		}
	}
}
void solve(){
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++) w[i]=read();
	memset(t,0,sizeof(t));
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			int a=read(),b=read();
			t[i][a]=b;
		}
	}
	while(q--){
		int x=read(),y=read();
		ans=INT_MAX;
		dfs(x,y,0,0);
		cout<<w[x]+ans+w[y]<<endl;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}	
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
//Oct31==Dec25?
