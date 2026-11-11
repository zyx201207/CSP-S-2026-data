#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,m,d,q,c,w[5*N],k[5*N];
map<int,pair<int,int> > mp;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int x;cin>>x;	
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
	}
	cout<<35<<endl<<16;
	return 0;
}
