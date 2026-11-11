#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int M=5e5+5;
int c,n,m,d,q,x,y;
int w[N],k[N],t[N][M],a[N][M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	int t1=t[1][1];
	int ans;
	while(q--){
		ans=0;
		cin>>x>>y;
		ans=(y-x)*t1+w[x]+w[y];
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
