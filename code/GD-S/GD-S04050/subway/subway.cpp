#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,w[N],k[510],a[510][N],t[510][N];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	
	while(q--){
		int x,y;
		cin>>x>>y;
		
	}
	return 0;
} 
