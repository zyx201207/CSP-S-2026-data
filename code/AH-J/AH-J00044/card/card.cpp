#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],zen[500005],qu[500005],yi[500005];
int last[500005],xia[500005],xiaa[500005],times[500005];
int ans[500005];
struct node{
	int n,jie;
};
vector<node> v;
void dfs(int x){
	if(v[x].jie==-1){
		ans[v[x].n]++;
		return;
	}
	ans[v[x].n]++;
	dfs(v[x].jie);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(last,-1,sizeof(last));
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		zen[i]=last[a[i]];
		last[a[i]]=i;
	}
	memset(last,-1,sizeof(last));
	for(int i=n;i>=1;i--){
		qu[i]=last[a[i]];
		last[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		int t=i;
		if(qu[i]==-1){
			xia[a[i]]=i;
			xiaa[i]=a[i];
			while(zen[t]!=-1){
				t=zen[t];
				yi[t]=i;
			}
			yi[i]=i;
		}
	}
	for(int i=1;i<=n;i++){
		times[a[yi[i]]]++;
	}
	v.push_back({-1,-1});
	for(int i=1;i<=m;i++){
		int j=xia[i];
		v.push_back({i,-1});
		if(j==n) continue;
		while(1){
			j++;
			if(qu[j]!=-1){
				j=qu[j];
			}else{
				v[i].jie=a[j];
				break;
			}
		}
	}
	for(int i=1;i<=n;i++){
		dfs(a[yi[i]]);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
