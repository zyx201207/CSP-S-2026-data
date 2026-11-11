#include<bits/stdc++.h>
using namespace std;
int xl[500010][500010];
int zl[500010];
int c,m,n,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>m>>n>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>zl[i];
	}for(int i=1;i<=m;i++){
		int a,z1,z2,t1,t2;
		cin>>a>>z1>>t1>>z2>>t2;
		xl[z1][z2]=t1+t2;
		xl[z2][z1]=t1+t2;
	}for(int i=1;i<=q;i++){
		int ans=0,b,f;
		ans+=zl[b];
		ans+=zl[f];
		
	}
	return 0;
}
