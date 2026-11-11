#include<iostream>
#include<vector>
using namespace std;
int c,t;
int n;
long long d;
long long x[(int)2e6+5];
int nxt[(int)2e6+5],lst[(int)2e6+5];
vector<int> g[(int)2e6+5];
int fa[(int)2e6+5];
int val1[(int)2e6+5],val2[(int)2e6+5],val3[(int)2e6+5],val4[(int)2e6+5];
bool flag[(int)2e6+5];
int sum2[(int)2e6+5],sum3[(int)2e6+5];
int up[(int)2e6+5];
long long ans;
void dfs(int now,int fath){
	fa[now]=fath;
	if(fa[fath]){
		if(lst[fa[fath]]<fath){
			val1[now]=1;
			if(lst[fa[fath]]<fath-1||lst[lst[fa[fath]]]<now) flag[now]=true;
		}
		int l=fath,r=fa[fath];
		while(l<r){
			int mid=(l+r+1)>>1;
			if(lst[mid]<fath) l=mid;
			else r=mid-1;
		}
		val3[now]=fa[fath]-l;
		int L=fath+1,R=l;
		while(L<R){
			int mid=(L+R)>>1;
			if(lst[mid]==fath-1) R=mid;
			else L=mid+1;
		}
		if(lst[L]==fath-1){
			val4[now]=l-L+1;
			if(lst[fath-1]==now) val2[now]=l-L+1;
		}
	}
	sum2[now]=sum2[fath]+val2[now],sum3[now]=sum3[fath]+val3[now];
	for(int i=0;i<g[now].size();i++) dfs(g[now][i],now);
}
void dfs2(int now,int fath){
	if(val1[now]) up[now]=now;
	else up[now]=up[fath];
	ans+=sum2[fa[now]]-sum2[fa[up[now]]]+val4[now];
	if(up[now]==now){
		if(lst[fa[fath]]==fath-1) ans+=sum3[fa[up[now]]]-sum3[up[fa[up[now]]]];
	}else if(!flag[up[now]]) ans+=sum3[fa[up[now]]]-sum3[up[fa[up[now]]]];
	for(int i=0;i<g[now].size();i++) dfs2(g[now][i],now);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int p=n;
		for(int i=n;i>=1;i--){
			while(x[p]-x[i]>d) p--;
			nxt[i]=p;
		}
		p=1;
		for(int i=1;i<=n;i++){
			while(x[i]-x[p]>d) p++;
			lst[i]=p;
		}
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++) if(nxt[i]>i) g[nxt[i]].push_back(i);
		for(int i=1;i<=n;i++) val1[i]=val2[i]=val3[i]=val4[i]=flag[i]=0;
		for(int i=1;i<=n;i++) if(nxt[i]==i) dfs(i,0);
		ans=0;
		for(int i=1;i<=n;i++) if(nxt[i]==i) dfs2(i,0);
		cout<<ans<<'\n';
	}
	return 0;
}

