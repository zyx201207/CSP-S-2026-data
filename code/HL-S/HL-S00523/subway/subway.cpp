#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int M=5e5+5;
int c,n,m,d,q,cntk[501];
vector<int> line[505],dis,cr[505];
void dfs(int u,int fin,vector<int> tmp){
	if(u==fin){
		for(auto it:tmp){
			dis.push_back(it);
		}
		return;
	}
	for(auto v:cr[u]){
		tmp.push_back(v);
		dfs(v,fin,tmp);
		tmp.pop_back();
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	vector<int> w(m+1);
	for(int i=1;i<=m;i++) cin>>w[i];
	vector<vector<int>> a,t;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		cntk[i]=k;
		a.resize(n+1,vector<int>(k+1));
		t.resize(n+1,vector<int>(k+1));
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=cntk[i];j++){
			for(int x=j+1;x<=cntk[i];x++){
				cr[a[i][j]].push_back(a[i][x]);
				line[i].push_back(a[i][j]);
			}
		}
	}
	while(q--){
		ll ans=0;
		int from,to;
		cin>>from>>to;
		dis.clear();
		dis.push_back(from);
		vector<int> tmp;
		dfs(from,to,tmp);
		int cnt=0,now=from,nl=-1;
		ans+=w[from];
		for(auto x:dis){
			bool got=0,change=0;
			for(int i=1;i<=n;i++){
				for(auto it:line[i]){
					if(x==it){
						if(nl==-1){
							nl=i;
						}else if(nl!=i){
							ans+=t[i][i];
							change=1;
						}
						now=it;
						if(change) nl=i;
						ans+=t[nl][now];
						got=1;
						break;
					}
				}
				if(got) break;
			}
		}
		cout<<ans+w[to]<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}