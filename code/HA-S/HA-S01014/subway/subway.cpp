#include <bits/stdc++.h>
using namespace std;
int w[50005];
int c,n,m,d,q,sum;
int a[5005][5005];
int t[505][50005];
int main(){
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
			cin>>a[i][j]>>t[i][j];
			sum+=a[i][j];
		}
	}
	while(q--){
		int x,y;
		cout<<rand()%(sum/x+y)<<endl;
	}
	return 0;
}
