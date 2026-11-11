#include <bits/stdc++.h>
using namespace std;
long long n,m,q,c,d,w[500005],k[500005];
int main(){
	freopen("subway.in","r",stdin); 
	freopen("subway.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<=m;j++){
		cin>>k[i];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		}
	cout<<k;
	return 0;
}
