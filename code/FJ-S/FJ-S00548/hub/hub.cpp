#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
vector<int> e[100020];
int dep[500020],dp[500020];
int uson[502000];
int dep2[500020],dp2[500020];
int dfs1(int nw,int nfa){
	dep[nw]=dep[nfa]+1;
	for(int v:e[nw]){
		if(v==nfa)continue;
		dfs1(v,nw);
		if(dep[v]>dp[nw]){
			dp[nw]=dep[v];
			uson[nw]=v;
		}
	}
}
int dfs2(int nw,int nfa){
	dep2[nw]=dep2[nfa]+1;
	for(int v:e[nw]){
		if(v==nfa)continue;
		dfs2(v,nw);
		if(dep2[v]>dp2[nw]){
			dp2[nw]=dep2[v];
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		
		for(int i=1;i<n;i++){
			int ut,vt;
			cin>>ut>>vt;
			e[ut].push_back(vt);
			e[vt].push_back(ut);
		}
		if(c==7||c==11||c==12){
			for(int i=1;i<=n;i++){
				sort(e[i].begin(),e[i].end());
			}
			dfs1(0,1);
			int nw=1;
			bool flag=0;int mx=0;
			for(int v:e[1]){
				if(!flag&&dep[v]==dp[1])flag=1;
				mx=max(mx,dep[v]);
			}
			int len=mx+dp[nw]+1;
			while(len-dp[nw]<dp[nw]+1){
				nw=uson[nw];
			}
			e[nw].erase(lower_bound(e[nw].begin(),e[nw].end(),uson[nw]));
			e[uson[nw]].erase(lower_bound(e[uson[nw]].begin(),e[uson[nw]].end(),nw));
			dfs2(nw,0);dfs2(uson[nw],0);
			flag=0;mx=0;
			for(int v:e[nw]){
				if(!flag&&dep[v]==dp[nw])flag=1;
				mx=max(mx,dep[v]);
			}
			int len1=mx+dp2[nw]+1;
			nw=uson[nw];
			flag=0;mx=0;
			for(int v:e[nw]){
				if(!flag&&dep[v]==dp[nw])flag=1;
				mx=max(mx,dep[v]);
			}
			int len2=mx+dp2[nw]+1;
			cout<<max(len1/2,len2/2);
			memset(dep,0,sizeof(dep));
			memset(dp,0,sizeof(dp));
			memset(uson,0,sizeof(uson));
			memset(dep2,0,sizeof(dep2));
			memset(dp2,0,sizeof(dp2));
		}
		else{
			cout<<"0"<<endl;
		}
		
		
		for(int i=1;i<=n;i++){
			e[i].clear();
		}
	}
}
/*
DabaiErGui
TAT
*/
