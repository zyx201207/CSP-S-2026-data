#include <bits/stdc++.h>;
using namespace std;
const long long M=5e5+10;
const long long N=1e9+10;
long long c,n,m,d,q,w[N],k[510],a[M],t[M],x,y;
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[m];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=2*k[i];j++){
			cin>>a[i]>>t[i]
		}
	}
	while(q--){
		cin>>x>>y;
	}
	if(m==1){
		cout<<0;
		return 0;
	}
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	return 0;
}
