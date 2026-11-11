#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,k,x,y;
int tu[130000][130000],w[130000],t[130000][130000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		int a[k+10];
		for(int j=1;j<=k;j++){
			cin>>a[i]>>t[i][j];
			t[j][i]=t[i][j];
		}
		for(int j=2;j<=k;j++){
			tu[a[i]][a[i-1]]=1;
			tu[a[i-1]][a[i]]=1;
		}
	}
	cin>>x>>y;
	return 0;
}
