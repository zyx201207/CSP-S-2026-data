#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k;int c,t;
int g[10020][10020];
int du[10010];
int ans[10];
vector<int> pq;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			g[i][j]=INT_MAX/2;
		}
	}
	for(int p=1;p<=t;p++){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;cin>>x,y;
			g[x][y]=g[y][x]=1;
			du[x]++;du[y]++;
		}
		int dux=0;
		for(int i=1;i<=n;i++){
			dux=max(dux,du[i]);
		}
		if(n<=5&&k>=2){
			ans[p]=1;
		}
		if(n<=5&&k==1){
			if(dux==n-1) ans[p]=1;
			else ans[p]=2;
		}
	}
	for(int i=1;i<=t;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
} 
