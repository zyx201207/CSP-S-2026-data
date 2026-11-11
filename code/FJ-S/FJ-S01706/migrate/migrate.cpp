#include<bits/stdc++.h>
using namespace std;
#define int long long
void dd(int &ss){
	ss=0;
	char ch=getchar();int ff=1;
	while(ch<'0'||ch>'9'){if(ch=='-')ff=-1;ch=getchar();}
	while('0'<=ch&&ch<='9')ss=ss*10+ch-'0',ch=getchar();
	ss*=ff;
}
const int N=4e6+5;
int n,d;
int c,t,x[N],nxt[N],dep[N][4],bb[N][4];
int dfs(int x,int op){
	if(op>=3||nxt[x]==x)return 0;
	if(bb[x][op])return dep[x][op];
	bb[x][op]=1;
	int y=nxt[x],opp=op;
	op+=(nxt[x-1]==y);
	if(op==1){
		if(y-1!=x&&nxt[x-1]<y-1)dep[x][opp]+=nxt[y-1]-nxt[y-2];
	}else if(op==2){
		dep[x][opp]+=nxt[y]-nxt[y-1];
	}
	if(x!=nxt[x]){
		if(nxt[y-2]==nxt[y])op=3;
		if(nxt[y-1]==nxt[y]&&nxt[x-1]>=y-1)op=3;
		dep[x][opp]+=dfs(y,op);
	}
	return dep[x][opp];
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	dd(c),dd(t);int id=0;
	while(t--){++id;
		dd(n),dd(d);
		for(int i=1;i<=n;++i)dd(x[i]),dep[i][1]=dep[i][2]=bb[i][1]=bb[i][2]=0;
		int r=1;
		for(int i=1;i<=n;++i){
			while(r<=n&&x[r]-x[i]<=d)++r;
			nxt[i]=r-1;
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			int y=nxt[i];
			if(nxt[y]!=y){
				if(y!=i+1)ans+=nxt[y-1]-nxt[y-2];
				int op=1;
				if(nxt[y-1]==nxt[y])++op;
				if(y-2>=i&&nxt[y-2]==nxt[y])++op;
				if(op<=2)
				ans+=dfs(y,1);
			}
		}
		cout<<ans<<'\n';
	}
}
