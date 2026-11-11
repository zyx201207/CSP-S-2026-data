#include<bits/stdc++.h>
using namespace std;
const int Q=1e5+5,K=5e5+5;
struct node{
	int x,y;
}r[Q];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	int w[m+5];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}int k[n+5];
	pair<int,int> a[K][n+5];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[j][i].first>>a[j][i].second;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>r[i].x>>r[i].y;
		int ans=0;
		ans+=w[r[i].x];
		ans+=w[r[i].y];
		for(int j=1;j<=k[i];j++){
			if(a[i][j].first==r[i].x or a[i][j].first==r[i].y){
				ans+=a[i][j].second;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
