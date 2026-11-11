#include<bits/stdc++.h>
using namespace std;
const int N = 1100;
int c,n,m,d,q;
int a[N],tl[N][3],G[N][N],GT[N][N],aa[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=m;j++){
			G[i][j]=INT_MAX;
		}
	}
	for(int i = 1;i<=m;i++){
		cin>>a[i];
	}
	for(int i = 1;i<=n;i++){
		int x,ttt[N],lenth[N];
		cin>>x;
		for(int j = 1;j<=x;j++){
			cin>>ttt[j];
			cin>>lenth[ttt[j]];
		}
		for(int j = 1;j<=x;j++){
			for(int k = 1;k<=x;k++){
				G[ttt[j]][ttt[k]+500]=lenth[ttt[k]];
				G[ttt[k]+500][ttt[j]]=lenth[ttt[k]];
			}
		}
	}
	for(int i = 1;i<=q;i++){
		cin>>tl[i][1]>>tl[i][2];
	}
	for(int i = 1;i<=m;i++){
		for(int j = 1;j<=m;j++){
			for(int k = 1;k<=m;k++){
				GT[i][j]=min(GT[i][j],G[i][k+500]+G[k+500][j]);
			}
		}
	}
	for(int i = 1;i<=n;i++){
		cout<<aa[tl[i][1]]+aa[tl[i][2]]+G[tl[i][1]][tl[i][2]];
	}
	return 0;
	}
