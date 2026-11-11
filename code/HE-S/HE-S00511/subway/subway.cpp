#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int c,n,m,d,q; 
int way[N];
int k[555],a[505][20055],t[505][20005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>way[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int kk=1;kk<=k[i];kk++){
			int x;
			cin>>a[i][kk]>>x;
			t[i][a[i][kk]]=max(t[i][a[i][kk]],x);
		}
	}
	for(int qq=1;qq<=q;qq++){
		int r,z;
		cin>>r>>z;
		cout<<way[r]+t[r][r]+t[r][z]+way[z]<<endl;
	}
	return 0;
}
