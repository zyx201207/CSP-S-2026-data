#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int w[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int minn=INT_MAX;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		int aab=0;
		for(int j=1;j<=2*k;j+=2){
			int o,p;
			cin>>o>>p;
			minn=min(minn,p);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+w[y]+2*minn<<endl;
	}
	return 0;
}
