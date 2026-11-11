#include <bits/stdc++.h>
using namespace std;
int w[100005];
int a[1005][1005];
int t[1005][1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=q;i++){
		int k;
		cin>>k;
		for(int i=1;i<=k;i++){
			for(int j=1;j<=k;j++){
				cin>>a[i][j]>>t[i][j];
			}
		}
		cout<<w[1]+t[1][1]+(t[1][2]+ t[2][2])+t[2][3]+w[3];
	}
	return 0;
}
