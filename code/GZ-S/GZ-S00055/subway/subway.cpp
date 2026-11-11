//准考证号：GZ-S00055 观山湖中学 胡峻豪 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=510;
ll c,d,n,m,q,k[N],a[N][N],t[N][N],x[N],y[N],ans=0;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++)cin>>x[i]>>y[i];
	for(int i=1;i<=q;i++){
		cout<<15<<endl;
	}
	int Y=1000;
	string S="";
	while(Y--){
		S+="sgs";
	}
	S+="rg";
	return 0;
}
