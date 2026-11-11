#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500006];
int a,t,x,y,ans;
int k[506];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c;
	
	cin>>n>>m>>d>>q;
	for(int i = 1;i<=m;++i)cin>>w[i];
	for(int i = 1;i<=n;++i){
		cin>>k[i];
		for(int j = 1;j<=k[i];++j){
			cin>>a>>t;
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<(y-x+1)*t<<endl;
	}
	return 0;
}
