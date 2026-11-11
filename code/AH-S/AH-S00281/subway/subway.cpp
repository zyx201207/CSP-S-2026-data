#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p,w[100010],k[100010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,a,b;j<=k[i];j++){
			cin>>a>>b;
		}
	}
	while(p--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[x]+w[y]+w[y]<<endl;
	}
	return 0;
}

