#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,k,ans;
struct node{
	int fa,dep;
	queue<int> q;
}tree[1000005];
void clean(){
	n=0,k=0,ans=1000005;
	for(int i=1;i<=1000000;i++){
		tree[i].fa=0;
		tree[i].dep=0;
	}
}
void F(int a,int b){
	while(!tree[a].q.empty()){
		int t=tree[a].q.front();
		tree[a].q.pop();
		if(t==b) continue;
		tree[t].fa=a;
		tree[t].dep=tree[a].dep+1;
		F(t,a);
	}
}
void add(int a,int b){
	if(a==1||tree[a].fa!=0){
		tree[b].fa=a;
		tree[b].dep=tree[a].dep+1;
		F(b,a);
	}
	else if(b==1||tree[b].fa!=0){
		tree[a].fa=b;
		tree[a].dep=tree[b].dep+1;
		F(a,b);
	}
	else{
		tree[a].q.push(b);
		tree[b].q.push(a);
	}
}
int lca(int a,int b){
	int ans=0;
	while(a!=b){
		if(tree[a].dep>tree[b].dep){
			a=tree[a].fa;
			ans++;
		}
		else{
			b=tree[b].fa;
			ans++;
		}
	}
	cout<<ans;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdin);
	cin>>c>>t;
	while(t--){
		clean();
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			add(u,v);
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int R=0;
				for(int k=1;k<=n;k++){
					if(k==i||k==j) continue;
					R=max(R,min(lca(k,i),lca(k,j)));
				}
				ans=min(ans,R);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
