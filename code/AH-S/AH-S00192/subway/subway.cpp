#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int w[1010],a[550][550],tt[510][510],t[510][510],cnt[510][510],h[510][510];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1; i<=m; i++){
		cin>>w[i];
	}
	for(int i=1; i<=n; i++){
		int k;
		cin>>k;
		for(int j=1; j<=k;j++){
			cin>>a[i][j]>>tt[i][j];
			t[i][a[i][j]]=tt[i][j];
		}
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i!=j){
				for(int k=1; k<=m; k++){
					if(t[i][k]&&t[j][k]){
						h[i][j]=k;
						h[j][i]=k;
					} 
				}
			}
		}
	}
	for(int i=1; i<=q; i++){
		int x,y;
		cin>>x>>y;
		int ans=w[x]+w[y],minn=1e9;
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i==j&&t[i][x]&&t[i][y]) minn=min(minn,t[i][x]+t[j][y]); 
				else if(t[i][x]&&t[j][y]&&t[i][h[i][j]]&&t[j][h[i][j]]){
					 minn=min(minn,t[i][x]+t[j][y]+t[i][h[i][j]]+t[j][h[i][j]]); 
				}
			}
		}
		ans+=minn;
		cout<<ans<<endl;
		//djs(x);
		//cout<<dis[y];
	}
	return 0;
}

/*
太tm难了 我tm djs忘了！
*/