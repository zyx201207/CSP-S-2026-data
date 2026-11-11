#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

long long n,m,a[600100],h[600100],r,l,mn,mid,x,ans=1e18,c,d,q,ln[1000][1000];
vector<pair<int,long long> > k[600100];

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++){
		cin >> a[i];
	}
	for(int i=1;i<=550;i++){
		for(int j=1;j<=550;j++){
			ln[i][j]=1e18;
			if(i==j){
				ln[i][j]=0;
			}
		}
	}
    for(int i=1;i<=n;i++){
		cin >> x;
		for(int j=1;j<=x;j++){
			cin >> l >> r;
			for(auto u:k[l]){
				ln[u.fi][i]=ln[i][u.fi]=min(ln[i][u.fi],u.se+r);
			}
			k[l].push_back({i,r});
		}
	}
    for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int o=j+1;o<=n;o++){
				ln[o][i]=ln[i][o]=min(ln[i][o],ln[i][j]+ln[j][o]);
			}
		}
	}
	//for(int i=1;i<=n;i++){
	//	for(int j=1;j<=n;j++){
	//		cout << ln[i][j] << " ";
	//	}
	//	cout << endl;
	//}
    for(int i=1;i<=q;i++){
		cin >> l >> r;
		for(auto u:k[l]){
			for(auto v:k[r]){
				ans=min(ans,ln[u.fi][v.fi]+u.se+v.se);
			}
		}
		cout << ans+a[l]+a[r] << "\n";
		ans=1e18;
	}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}
