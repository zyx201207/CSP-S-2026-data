#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q,w[500005],k[502],a[502][500005],t[502][500005],x,y;
vector<int>kei[502],sttion[500005];

int work(int x,int y){
	int ret=w[x]+w[y];
	
	
	
}

int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			kei[i].push_back(a[i][j]);
			sttion[a[i][j]].push_back(i);
		}
	}
	
	while(q--){
		
		cin>>x>>y;
		
		cout<<work(x,y)<<'\n';
		
	}
	
	return 0;
}
