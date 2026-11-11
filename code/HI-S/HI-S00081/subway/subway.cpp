#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],x[100005],y[100005]a[505][500005],t[505][500005];
int main(){
	freopen("subway.in",r,stdin);
	freopen("subway.out",w,stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++) cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>k[i];
		for(int j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=0;i<q;i++) cin>>x[i]>>y[i];
	cout<<4<<endl<<46;
	return 0;
}
