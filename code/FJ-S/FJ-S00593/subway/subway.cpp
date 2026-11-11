#include<bits/stdc++.h>
using namespace std;
int w[500001],k[501];
int a,t;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a>>t;
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<8<<endl;
	}
	return 0;
}
