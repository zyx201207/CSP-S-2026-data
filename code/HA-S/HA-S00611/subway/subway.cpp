#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
const int N=1e5+5;
int t[505][505],a[505][505];
/*
XIE LAO SHI ZUI SHUAI  XIE LAO SHI ZUI SHUAI 
XIE LAO SHI ZUI SHUAI  XIE LAO SHI ZUI SHUAI 
XIE LAO SHI ZUI SHUAI  XIE LAO SHI ZUI SHUAI
XIE LAO SHI NIU BI PLUS  XIE LAO SHI NIU BI PLUS
PIAN FEN PIAN FEN PIAN FEN PIAN FEN PIAN FEN 
XIE LAO SHI NIU BI PLUS  XIE LAO SHI NIU BI PLUS
PIAN FEN PIAN FEN PIAN FEN PIAN FEN PIAN FEN 
XIE LAO SHI NIU BI PLUS  XIE LAO SHI NIU BI PLUS
PIAN FEN PIAN FEN PIAN FEN PIAN FEN PIAN FEN 
XIE LAO SHI NIU BI PLUS  XIE LAO SHI NIU BI PLUS
PIAN FEN PIAN FEN PIAN FEN PIAN FEN PIAN FEN 
XIE LAO SHI NIU BI PLUS  XIE LAO SHI NIU BI PLUS
PIAN FEN PIAN FEN PIAN FEN PIAN FEN PIAN FEN 
XIE LAO SHI NIU BI PLUS  XIE LAO SHI NIU BI PLUS
PIAN FEN PIAN FEN PIAN FEN PIAN FEN PIAN FEN 
XIE LAO SHI NIU BI PLUS  XIE LAO SHI NIU BI PLUS
PIAN FEN PIAN FEN PIAN FEN PIAN FEN PIAN FEN 
XIE LAO SHI NIU BI PLUS  XIE LAO SHI NIU BI PLUS
PIAN FEN PIAN FEN PIAN FEN PIAN FEN PIAN FEN 
XIE LAO SHI NIU BI PLUS  XIE LAO SHI NIU BI PLUS
PIAN FEN PIAN FEN PIAN FEN PIAN FEN PIAN FEN 
XIE LAO SHI NIU BI PLUS  XIE LAO SHI NIU BI PLUS
*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	int w[N];
	for(int i=1;i<=m;i++)cin>>w[i];
	
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		int tot=w[u]+w[v];
		tot+=(t[1][u]+t[1][v]);
		cout<<tot<<"\n";
	}
	return 0;
}