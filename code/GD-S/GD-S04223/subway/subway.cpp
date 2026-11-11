#include<iostream>
using namespace std;
long long c,n,m,d,q,w[100005],a[1005][10005],t[1005][1005],k,x,y;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][a[i][j]];
		}
	}while(q--){
		cin>>x>>y;
		long long ans=w[x]+w[y];
		//cout<<w[x]<<' '<<w[y]<<' ';
		for(int i=x;i<y;i++){
			//cout<<t[i][i]<<' '<<t[i][i+1]<<' ';
			ans+=t[i][i]+t[i][i+1];
		}cout<<ans<<'\n';
	}
    
    

	return 0;
}
