#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[500005],a[500][500005],t[500][500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
		cout<<endl;
	}
	return 0;
}
