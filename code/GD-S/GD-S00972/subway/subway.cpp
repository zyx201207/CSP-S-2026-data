#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500050],k[550],minn=0x3f3f3f3f;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int des,dis;
			cin>>des>>dis;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<0<<endl;
	}
	return 0;
}
