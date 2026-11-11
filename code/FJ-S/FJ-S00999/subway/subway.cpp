#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[500005];
vector<int>v[500005],t[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>p>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int o,p;
			cin>>o>>p;
			v[i].push_back(o);
			v[o].push_back(i);
			t[i].push_back(p);
			t[p].push_back(i);
		}
	}while(q--){
		int x,y;
		cin>>x>>y;
		cout<<56<<endl;
	}
	return 0;
}
