#include<bits/stdc++.h>
using namespace std;
bool f=0;
int w[500005];
vector <int> v[500005];
vector <int> z;
int a[505][500005];
int t[505][500005];
void dfs(int x,int y){
	for(int i=0;i<v[x].size();i++){
		int t=v[x][i];
		if(t==y){
			z.push_back(t);
			f=1;
			return;
		}else {
			z.push_back(t);
			dfs(t,y);
			v[x].pop();
		}
	}
}
void zpop(){
	while(z.empty()){
		z.pop;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][ j];
			v[i].push_back(j);
			v[j].push_back(i);
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		f=0;
		int x,y,ans=0;
		cin>>x>>y;
		dfs(x,y);
		ans=ans+w[x]+t[x][x]+w[y];
		for(int i=0;i<z.size();i++){
			ans+=t[x][z[i]];
		}
		zpop();
		cout<<ans<<"\n"
	}
	return 0;
}
