#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<int> w,k;
int track[501];
int con[1001][1001];
int wait[10001][1001];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;w.resize(m+1);k.resize(n+1);
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int u,t;cin>>u>>t;
			if(track[u]){
				con[track[u]][i]=u;
				con[i][track[u]]=u;
			}
			track[u]=i;
			wait[i][u]=t;
		}
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		int s,t;
		cin>>s>>t;
		if(track[s]==track[t]){
			ans=w[s]+w[t]+wait[track[s]][s]+wait[track[t]][t];
		}else{
			ans=w[s]+w[t]+wait[track[s]][s]+wait[track[s]][con[s][track[s]]]+wait[track[t]][con[t][track[t]]]+w[t];
		}
		cout<<ans<<"\n";
	}
	return 0;
}
