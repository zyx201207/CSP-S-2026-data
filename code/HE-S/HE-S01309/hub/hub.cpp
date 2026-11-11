#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,minn;
int v[1000000];
struct lp{
	int le;
	int s[100];
}tree[1000000];
void cov(int need,int step,int deep,int now){
	if(step==deep) return;
	for(int i=1;i<=tree[now].le;i++){
		v[tree[now].s[i]]=1;
		cov(need,step,deep+1,tree[now].s[i]);
	}
}
bool find(int l,int r,int step){
	if(step==0) return true;
	cov(l,step,0,l);
	cov(r,step,0,r);
	for(int i=1;i<=n;i++){
		if(!v[i]) return true;
	}return false;
}
void dfs(int l,int r){
	int cnt=0;
	while(find(l,r,cnt)){
		memset(v,0,sizeof(v));
		++cnt;
	}minn=min(minn,cnt);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(tree,0,sizeof(tree));
		cin>>n>>k;minn=1e9;
		for(int i=1;i<=n;i++){
			int l,r;
			cin>>l>>r;
			tree[l].le++;
			tree[l].s[tree[l].le]=r;
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				dfs(i,j);
			}
		}cout<<minn<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
