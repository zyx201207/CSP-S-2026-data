#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int c,n,m,d,q,a[505][505],w[500005];
vector<int>g[505];
struct oo{
	int c,t;
}r[505];
struct ooo{
	int t;
}p[505];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>r[j].c>>r[r[j].c].t;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=w[i]+w[j]+r[i].t+r[j].t;
		}
	}
	for(int i=1;i<=q;i++){
		int v,u;
		cin>>v>>v;
		cout<<a[v][u]<<endl;
	}
	return 0;
}
/*
     A             CCCCC      
    AA            C     C
   A  A          C       
  AAAAAA         C
 A      A         C     C
A        A         CCCCC
*/
