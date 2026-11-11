#include<bits/stdc++.h>
using namespace std;
int m,n,d,q,w[500010],k[500],a[500][500010],t[500][500010],x[500010],y[500010],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=0;i<q;i++){
		ans=w[x[i]]+w[y[i]];
		cout<<ans<<endl;
	}
	return 0;
}
