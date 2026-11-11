#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],a[505][1000005],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=0;i<=n;i++){
		int shu;
		cin>>shu;
		for(int j=1;j<=shu;j++){
			cin>>a[i][j];	
		}
	}
	int T=a[1][2];
	while(q--){
		cin>>x>>y;
		cout<<abs(x-y)*T*2+T*4;
	}
	return 0;
} 
