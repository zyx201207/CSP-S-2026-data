#include <bits/stdc++.h>

using namespace std;
//最大开两个1e8的int 
const int N=1e4+10;
typedef long long ll;
int n,m,c,d,q,k[N];
bool mk[N];
long long w[N],a[N][510],t[N][510],ans;
vector <int> v[N];
void dfs(int x,int y,ll z){
	if(x==y){
		ans=min(ans,z);
		return;
	}
	for(int i=0;i<v[x].size();i++){
		if(!mk[v[x][i]]){
			mk[v[x][i]]=1;
			dfs(i,y,t[i][x]+z);
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j][i]>>t[j][i];
			v[j].push_back(i);
		} 
	}
	for(int i=1;i<=q;i++){
		int s,e;
		cin>>s>>e;
		ans=1e18;
		memset(mk,0,sizeof(mk));
		dfs(s,e,0);
		cout<<ans<<"\n";
	}
	return 0;
}
