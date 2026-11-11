#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pa pair<int,int>
#define mkp make_pair
#define FI first
#define SE second
int c,n,m,d,q,w[500005],e[505][505];
vector<pa> num[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1,len,x,y;i<=n;i++){
		for(int j=1;j<=n;j++)e[i][j]=1e17;
		e[i][i]=0;
		cin>>len;
		for(int j=1;j<=len;j++){
			cin>>x>>y;
			num[x].push_back(mkp(i,y));
		}
	}
	for(int i=1;i<=m;i++){
		for(pa j:num[i]){
			for(pa k:num[i]){
				if(j==k)continue;
				e[j.FI][k.FI]=min(e[j.FI][k.FI],j.SE+k.SE);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			for(int k=1;k<=n;k++){
				if(i==k||j==k)continue;
				e[j][k]=min(e[j][k],e[j][i]+e[i][k]);
			}
		}
	}
	for(int i=1,x,y,ans;i<=q;i++){
		cin>>x>>y;
		ans=1e17;
		for(pa j:num[x]){
			for(pa k:num[y]){
				ans=min(ans,j.SE+k.SE+e[j.FI][k.FI]);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

