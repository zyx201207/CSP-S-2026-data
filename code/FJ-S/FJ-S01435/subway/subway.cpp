#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
vector<int>G[MAXN];
long long c,n,m,d,q,a[10010],vall[10010],mm[10010],mmii,ans,bj[10010],val[10010][10010],k,ss,ee;
void dfs(long long st,long long en){
	if(st==en){
		mmii=min(mmii,ans);
		return;
	}
	for(long long i=0;i<G[st].size();i++){
		if(bj[i]==0){
		ans+=(val[st][G[st][i]]+val[G[st][i]][G[st][i]]);
		bj[i]=1;
		dfs(G[st][i],en);
		bj[i]=0;
		ans-=(val[st][G[st][i]]+val[G[st][i]][G[st][i]]);	
		}
	}
}
int main(){
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>mm[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>k;
		memset(a,0,sizeof(a));
		memset(vall,0,sizeof(vall));
		for(long long j=1;j<=k;j++){
		cin>>a[j];
		cin>>vall[j];
		vall[j]+=vall[j-1];
		}
		a[0]=a[1];
		for(long long j=0;j<=k;j++){
			for(long long l=0;l<j;l++){
				G[a[j]].push_back(a[l]);
				G[a[l]].push_back(a[j]);
				val[a[j]][a[l]]=vall[j]-vall[l];
				val[a[l]][a[j]]=vall[j]-vall[l];
			}
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>ss>>ee;
		ans=0;
		mmii=2e64-1;
		memset(bj,0,sizeof(bj));
		bj[ss]=1;
		dfs(ss,ee);
		cout<<mmii+mm[ss]+mm[ee]+val[ss][ss]-val[ee][ee]<<endl;
	}
	return 0;
}
