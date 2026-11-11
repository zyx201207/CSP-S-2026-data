#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int c,tt,n,k;
vector <int> e[N];
long long bnd,fa[N],nfa[N],dp[N][5],lca[N][N],ldp[N];
void pre(){
	for(int i=1;i<=n;i++)  e[i].clear();
	for(int i=1;i<=n;i++)  fa[i]=0;
	
}

void dfs1(int np,int f){
	fa[np]=f;
	ldp[np]=ldp[f]+1;
	for(int i:e[np]){
		if(i==f)  continue;
		dfs1(i,np);
	} 
}

void dfs2(int np,int fr,int cs){
	nfa[np]=cs;
	for(int i:e[np]){
		if(i==fr || (i==bnd && np==fa[i]) || (np==i && i==fa[np]))  continue;
		dfs2(i,np,cs);
	}
}
long long tsz[N],dpt[N],sum;
priority_queue <long long> q;
void dfs3(int np,int fr,int f){
	tsz[np]=1;
	dpt[np]=dpt[fr]+1;
	for(int i:e[np]){
		if(nfa[i]!=nfa[np] || i==fr)  continue;
		dfs3(i,np,f);
		tsz[np]+=tsz[i];
	}
	q.push(dpt[np]);
	sum+=dpt[np];
} 

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>tt;
	while(tt--){
		cin>>n>>k;
		pre();
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
			
		}
		if(k==n){
			cout<<0<<'\n';
			continue;
		}
		else if(n-k<=2){
			cout<<1<<'\n';
			continue;
		}
		dfs1(1,1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)  lca[i][j]=i;
				else{
					int u=i,v=j;
					if(ldp[u]<ldp[v])  swap(u,v);
					while(ldp[u]>ldp[v]) u=fa[u];
					if(u==v)  lca[i][j]=lca[j][i]=u;
					while(u!=v) u=fa[u],v=fa[v];
					lca[i][j]=lca[j][i]=u;
				}
			}
		}
	//	cout<<"<<<<<<<<<<<<<1"<<endl;
		long long ans=INT_MAX;
		for(int i=1;i<=n;i++){
			for(int i=0;i<=k;i++){
				dp[i][1]=dp[i][2]=INT_MAX;
			}
			bnd=i;
			for(int j=1;j<=n;j++)  nfa[j]=0;
			int cnt=0;
			for(int j=1;j<=n;j++){
				if(!nfa[j]) dfs2(j,j,++cnt);
			}
			for(int j=1;j<=n;j++){
				sum=0;
				dpt[j]=0;
				dfs3(j,j,j);
			//	cout<<dpt[2]<<" 666"<<endl;
				int nc=0;
				while(!q.empty()){
					long long np=q.top();q.pop();
					nc++;
					np--;
				//	cout<<i<<" "<<j<<" "<<nc<<" "<<np<<" ijncsum"<<endl;
					dp[nc][nfa[j]]=min(dp[nc][nfa[j]],np);
				}
			}
			if(i==1)  ans=min(ans,dp[k][1]);
			for(int j=1;j<k;j++)  ans=min(ans,max(dp[j][1],dp[k-j][2]));
			//cout<<i<<" "<<ans<<" ians"<<endl;
		}
		if(ans>2)  ans=2;
		cout<<ans<<'\n';
	}
	return 0;
} 

/*
-O2 -std=c++14 -static
-static-libgcc

0 1
5 2
1 2
2 3
3 4
4 5

0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

0 1
8 6
4 8
5 8
6 3
3 2
2 1
1 8
7 8

0 1
6 5
1 2
2 5
4 5
5 3
3 6
*/
