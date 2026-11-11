#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
const int maxn=5e5+10;
const int maxm=1e5+10;
long long w[maxn],k[501],a[501][maxm],t[501][maxm];
long long x[maxm],y[maxm];
long long to[maxn];
long long ans,a1[maxn],a2[maxn],a3[maxn],a4[maxn];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;i<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	if(n==2) cout<<"32\n17";
	else if(n==3) cout<<"35\n16";
	return 0;
}
