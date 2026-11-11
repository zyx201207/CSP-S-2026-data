#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Please return
#define AC 0
int c,n,m,d,q,w[500005],k[255],place,x,y,f;

	int a[200][5050];
	int t[200][5050];

/*
void dfs(int bilibili){
	if(bilibili>n) return;
	for (int i=0;i<;i++){
		if(){
			dfs(bilibili++);
		}
	}
}*/
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin>>c>>n>>m>>d>>q;
    for (int i=0;i<m;i++) cin>>w[i];
    for (int i=0;i<n;i++){
	    cin>>k[i];
	    for (int j=0;j<k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	for (int i=0;i<q;i++){
		cin>>x>>y;
		f=0;
		f+=w[x]+w[y];
		for (int qq=0;qq<n;qq++){
			for (int j=0;j<k[qq];j++){
				if (a[qq][j]==x||a[qq][j]==y) f+=t[qq][j];
//				cout<<a[qq][j]<<' '<<x<<' '<<y<<endl
			}
		}
		cout<<f<<endl;
	}
    Please AC;
}
