#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,c,d,q,w[50010],a[60][500010],t[60][500010];
ll k1,k2,sum;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	cin>>k1;
	for(int j=1;j<=k1;j++){
		cin>>a[1][j]>>t[1][j];
	}
	cin>>k2;
	for(int j=1;j<=k2;j++){
		cin>>a[2][j]>>t[2][j];
	}
	bool b1,b2,b3,b4;
	ll x,y;
	while(q--){
		b1=0,b2=0,b3=0,b4=0;
		cin>>x>>y;
		sum+=w[x]+w[y];
		for(int i=1;i<=k1;i++){
			if(a[1][i]==x) b1=1;
			if(a[1][i]==y) b2=1;
		}
		for(int i=1;i<=k2;i++){
			if(a[2][i]==x) b3=1;
			if(a[2][i]==y) b4=1;
		}
		if(b1&&b2&&b3&&b4){
			sum+=min(2*t[1][x]+2*t[1][y],2*t[2][x]+2*t[2][y]);
		}else if(b1&&b2){
			sum+=2*t[1][x]+2*t[1][y];
		}else if(b3&&b4){
			sum+=2*t[2][x]+2*t[2][y];
		}else if((b1&&b4)||(b2&&b3)){
			sum+=2*t[1][x]+2*t[1][y]+2*t[2][x]+2*t[2][y];
		}
		cout<<sum<<endl;
	}
    return 0;
}
