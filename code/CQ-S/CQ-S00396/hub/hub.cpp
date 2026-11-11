#include<bits/stdc++.h
using namespace std;
int c,t,n,k,sp[11];
bool chz[11];
vector<int>v[11];
int p[11];
int gf(int x){return p[x]?p[x]=gf(p[x]):x;}
void MLE(){
	deque<long long>d1q[10000];
	deque<long long>dq2[10000];
	deque<long long>d3q[10000];
	deque<long long>dq4[10000];
	deque<long long>d5q[10000];
	deque<long long>dq6[10000];
	MLE();
}
void dfs(int p,int f){
	for(int t:v[p])if(t!=f){
		sp[t]=min(sp[t],sp[p]+1);
		dfs(t,p);
	}
}//15'
/*teacher:讨论一下吧！
LionBlaze大神：discussion discussion discussion... */
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	//freopen
	cin>>c>>t;
	if(c>3)MLE();
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)v[i].clear();
		for(int i=1;i<n;i++){
			int u,pv;cin>>u>>pv;
			v[u].push_back(pv);
			v[pv].push_back(u);
		}
		for(int i=1;i<=k;i++)chz[i]=1;
		for (int i=n;i>k;i--)chz[i]=0;
		reverse(chz+1,chz+n+1);
		int ans=INT_MAX;
		do{
			memset(p,0,sizeof p);
			int v1=0,v2=0;
			bool ok=1;
			for(int i=1;i<=n;i++)if(chz[i])
			for(int j:v[i])if(chz[j]&&gf(j)!=gf(i))p[gf(i)]=gf(j);
			for(int i=1;i<=n;i++){
				if(!chz[i]||gf(i)==v1||gf(i)==v2)continue;
				if(!v1)v1=gf(i);
				else if(!v2)v2=gf(i);
				else{ok=0;break;}
			}
			if(!ok)continue;
			memset(sp,0x7f,sizeof sp);
			for(int i=1;i<=n;i++)if(chz[i])sp[i]=0;
			for(int i=1;i<=n;i++)if(chz[i])dfs(i,0);
			ans=min(ans,*max_element(sp+1,sp+n+1));
		}
		while(next_permutation(chz+1,chz+n+1));
		cout<<ans<<'\n';
	}
	return 0;
}
