#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=6e5+15,inf=1e17+15;
int c,m,n,d,q,w[N],a[N][50],tl[N][50],wp[1000][1000],cnt[N],k[1000],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			
			wp[i][j]=inf;
			if(i==j) wp[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int num,t;
			cin>>num>>t;
			a[num][(++cnt[num])]=i;
			tl[num][cnt[num]]=t;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int y=j+1;y<=cnt[i];y++){
				
				wp[a[i][j]][a[i][y]]=min(tl[i][j]+tl[i][y],wp[a[i][j]][a[i][y]]);
				wp[a[i][y]][a[i][j]]=min(tl[i][j]+tl[i][y],wp[a[i][y]][a[i][j]]);
				//cout<<a[i][j]<<" "<<a[i][y]<<" "<<tl[i][a[i][j]]<<" "<<tl[i][a[i][y]]<<endl;
				//cout<<wp[a[i][j]][a[i][y]]<<endl;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int p=1;p<=n;p++){
				if(i==j||i==p||j==p||wp[j][i]==inf||wp[i][p]==inf) continue;
				wp[j][p]=min(wp[j][i]+wp[i][p],wp[j][p]);
				
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=inf;
		for(int j=1;j<=cnt[x];j++){
			for(int p=1;p<=cnt[y];p++){
				//cout<<w[x]<<" "<<w[y]<<" "<<a[x][j]<<" "<<a[y][p]<<" "<<wp[a[x][j]][a[y][p]]<<endl;
				ans=min(w[x]+w[y]+wp[a[x][j]][a[y][p]]+tl[x][j]+tl[y][p],ans);
			}
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
