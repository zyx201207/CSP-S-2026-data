#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m;
int a[N];
bool f[N];
int g[1100][1100],ans[N],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=0;i<m;i++){
		vector<int>e;
        bool vis[N]={0};
        e.clear();
		for(int j=1+i;j<=n;j++){
			if(vis[a[j]]){
				e.clear();
				g[i+1][a[j]]=0;
		    }
			e.push_back(a[j]);
			g[i+1][a[j]]++;
		    vis[a[j]]=1;
	    }
    }
    for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			ans[a[j]]+=g[i][a[j]];
		}
    }
    for(int i=1;i<=n;i++){
		if(f[ans[a[i]]]==0)cout<<ans[a[i]]<<" ";
		else f[ans[a[i]]]=1;
	}
    return 0;
}
