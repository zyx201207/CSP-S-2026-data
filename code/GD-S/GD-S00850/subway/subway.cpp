#include<bits/stdc++.h>

using namespace std;
const int maxn=510;
const int maxm=5e5+10;
int c,n,m,d,q;
long long w[maxm],k[maxn],submn[maxn][maxn];
vector<int> a[maxn];
vector<int> subtype[maxn];
vector<long long> t[maxn];
bool vis[maxn][maxn];
long long dfs(int subt1,int subt2){
	if(subt1==subt2) return 0;
	if(submn[subt1][subt2]!=1e14) return submn[subt1][subt2];
	if(vis[subt1][subt2]) {
		return 1e14;
	}
	vis[subt1][subt2]=true;
	vis[subt2][subt1]=true;
	int node,anotp,eid;
	for(int i=0;i<a[subt1].size();i++){
		node=a[subt1][i];
		for(int j=0;j<subtype[node].size();j++){
			anotp=subtype[node][j];
			if(subt1==anotp){
				eid=j;
				break;
			}
		}
		for(int j=0;j<subtype[node].size();j++){
			anotp=subtype[node][j];
			if(subt1==anotp) continue;
			submn[subt2][subt1]=min(submn[subt2][subt1],t[node][j]+t[node][eid]+dfs(anotp,subt2));
			submn[subt1][subt2]=submn[subt2][subt1];
		}
	}
	return submn[subt2][subt1];
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int temp1,temp2;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>temp1>>temp2;
			subtype[temp1].push_back(i);
			t[temp1].push_back(temp2);
			a[i].push_back(temp1);
		}
	}
	for(int j=1;j<=n;j++){
		for(int z=j+1;z<=n;z++){
			vis[j][z]=false;
			vis[z][j]=false;
			submn[j][z]=1e14;
			submn[z][j]=1e14;
		}
	}
	for(int j=1;j<=n;j++){
		for(int z=j+1;z<=n;z++){
			dfs(j,z);
		}
	}
	
	int l,r;
	long long ans;
	for(int tmp=1;tmp<=q;tmp++){
		cin>>l>>r;
		ans=1e14;
		for(int i=0;i<subtype[l].size();i++){
			for(int j=0;j<subtype[r].size();j++){
				int tp1=subtype[l][i];
				int tp2=subtype[r][j];
				ans=min(ans,t[l][i]+t[r][j]+submn[tp1][tp2]);
			}
		}
		cout<<ans+w[l]+w[r]<<'\n';
	}
	return 0;
}
