//GZ-S0031,罗义凯贵阳市第九中学 
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
#define ll long long
int c,n,m,d,q,a[maxn][maxn],t[maxn][maxn],k[maxn];
int w[maxn];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int xr,yr;
		cin>>xr>>yr;
		if(xr==yr){
			cout<<0<<'\n';
			break;
		}
		ll sum=0;
		sum+=w[xr]+w[yr];
		
		cout<<sum<<'\n'
	}
	return 0;
}
