#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;k++){
			int x,y;
			cin>>x>>y;
		}
	}
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		cout<<w[a]+w[b]<<endl;
	}
	return 0;
}

