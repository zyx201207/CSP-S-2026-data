#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node{int val,id;}end[233333];
bool cmp(node x,node y){return x.val>y.val;}
int n,m,a[500005],ans[233333],cnt[233333];
vector<int>son[233333];
void dfs(int now){
	for(int i=0;i<son[now].size();++i){
		int s=son[now][i];
		dfs(s);cnt[now]+=cnt[s];
	}
}
int read(){
	int res=0;char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
	return res;
}
signed main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;end[a[i]]=(node){i,a[i]},++cnt[a[i]],++i)
		a[i]=read();
	sort(end+1,end+m+1,cmp);
	for(int i=2;i<=m;++i)
		son[a[end[i].val+1]].push_back(end[i].id);
	dfs(end[1].id);
	for(int i=1;i<=m;++i)printf("%lld ",cnt[i]);
	return 0;
}
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
//AK CSP-J!!! on 11:58
