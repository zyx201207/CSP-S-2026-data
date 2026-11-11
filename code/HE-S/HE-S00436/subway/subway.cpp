#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005];
int k[505];
int a[505][500005];
int t[505][500005];
int iid[505];
int l[100005];
int r[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>iid[i];
		for(int j=1;j<=iid[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>l[i]>>r[i];
	}
	return 0;
}
