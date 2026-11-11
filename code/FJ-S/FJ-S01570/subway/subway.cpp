#include<bits/stdc++.h>
using namespace std;
const int maxm=5e5+5,maxn=505;
inline int read(){
	int x=0,f=0;
	char c=getchar();
	while(c<'0' || c>'9'){
		f=1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	if(f){
		x=-x;
	}
	return x;
}
int c,n,m,d,q,a,la,x,y;
int k[maxn];
struct tak{
	int nx;
	int id;
};
vector<tak> ta[maxn];
struct sta{
	int w,t[25];
};
sta st[maxm];
bool vis[maxm];
int ans;
void dfs(int s){
	int wt=0;
	ans=0x3f3f3f3f;
	int lid=0;
	if(s==y){
		wt+=st[s].t[lid];
		ans=min(wt,ans);
		return;
	}
	for(int i=0;i<ta[s].size();++i){
		if(!vis[ta[s][i].nx]){
			if(s==x){
				lid=ta[s][i].id;
				wt+=st[s].t[lid];
			}else if(ta[s][i].id!=lid){
				wt+=st[s].t[lid]+st[s].t[ta[s][i].id];
				lid=ta[s][i].id;
			}
			vis[ta[s][i].nx]=true;
			dfs(ta[s][i].nx);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read(),n=read(),m=read(),d=read(),q=read();
	for(int i=1;i<=m;i++){
		st[i].w=read();
	}
	for(int i=1;i<=n;i++){
		k[i]=read();
		for(int j=1;j<=k[i];j++){
			a=read();
			st[j].t[i]=read();
			if(j>1){
				ta[a].push_back({la,i});
				ta[la].push_back({a,i});
			}
			la=a;
		}
	}
	while(q--){
		x=read(),y=read();
		dfs(x);
		cout<<ans+st[x].w+st[y].w;
	}
	return 0;
}