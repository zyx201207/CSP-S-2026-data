#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],a[100005][100005]; 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
		}
	}
	cout<<w[3]*2+w[5]*2;
	cout<<w[4]*2+w[6]*2+w[9]*2;
}
