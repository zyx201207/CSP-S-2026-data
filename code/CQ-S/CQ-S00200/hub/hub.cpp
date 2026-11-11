#include<bits/stdc++.h>
using namespace std;
namespace lp{
	int t,n,k,x,y,a[15],pr[15],kl[15][15],b[15],d[15],cnt,cnt2,tmp,tmp2,ans;
	vector<int>v[15];
	bool vt[15],c[15];
	void dfs(int x,int prt){
		for(auto i:v[x]){
			if(i==prt || !c[i])continue;
			pr[i]=x,d[i]=d[x]+1,vt[i]=true,dfs(i,x);
		}
	}
	int LCA(int x,int y){
		if(d[x]<d[y])swap(x,y);
		while(d[x]!=d[y])x=pr[x];
		if(x==y)return x;
		while(pr[x]!=pr[y])x=pr[x],y=pr[y];
		return pr[x];
	}
	int main(){
		freopen("hub.in","r",stdin);
		freopen("hub.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0),cout.tie(0);
		cin>>x>>t;
		while(t--){
			cin>>n>>k;
			for(int i=1;i<=n;i++)v[i].clear(),c[i]=true;
			for(int i=1;i<=n-1;i++)cin>>x>>y,v[x].push_back(y),v[y].push_back(x);
			dfs(1,-1),ans=INT_MAX;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++)kl[i][j]=d[i]+d[j]-2*d[LCA(i,j)];
			}
			for(int i=0;i<(1<<n);i++){
				cnt=cnt2=0,memset(c,0,sizeof(c)),memset(vt,0,sizeof(vt)),tmp=0;
				for(int j=0;j<n;j++)if(i&(1<<j))b[++cnt]=j+1,c[j+1]=true;
				if(cnt!=k)continue;
				for(int j=1;j<=cnt;j++){
					if(!vt[b[j]])dfs(b[j],-1),cnt2++;
					if(cnt2>2)break;
				}
				if(cnt2>2)continue;
				for(int j=1;j<=n;j++){
					if(c[j])continue;
					tmp2=INT_MAX;
					for(int l=1;l<=cnt;l++)tmp2=min(tmp2,kl[j][b[l]]);
					tmp=max(tmp,tmp2);
				}
				ans=min(ans,tmp);
			}
			cout<<ans<<"\n";
		}
		return 0;
	}
}
int main(){
	lp::main();
	return 0;
}

