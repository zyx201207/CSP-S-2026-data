#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int c,n,m,d,q,k,mx,a[N],sx[501],s[501][2][N];
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int T,x,y;
		cin>>T;
		for(int j=1;j<=T;j++){
			cin>>x>>y;
			s[i][0][j]=x;
			s[i][1][j]=y;
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>>x>>y;
	}
	cout<<mx;
	return 0;
}
//Oct31==Dec25?

