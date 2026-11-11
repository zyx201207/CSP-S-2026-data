#include<bits/stdc++.h>
using namespace std;
int a[505][500005],t[505][500005];
bool vis[250005][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[m+3];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	long long k[n+3];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			vis[a[i][j]][i]=1;
		}
	}
	for(int i=1;i<=q;i++){
		int a,b,ans=0; 
		cin>>a>>b;
		ans+=w[a]+w[b];
		
	}
	return 0;
}

