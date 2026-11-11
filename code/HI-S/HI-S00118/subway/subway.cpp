#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[1005],road[505][1005][2],entrance,out;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>road[i][0][1];
		for(int j=1;j<=road[i][0][1];j++){
			cin>>road[i][j][0]>>road[i][j][1];
		}
	}
	while(q--){
		cin>>entrance>>out;
		int ans=w[entrance]+w[out];
		cout<<ans<<endl;
	}
	return 0;
}
