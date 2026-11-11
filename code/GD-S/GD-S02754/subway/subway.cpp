#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q;
int w[N],a[510][N],t[510][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	return 0;
}
