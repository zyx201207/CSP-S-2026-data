#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=50,NN=5e5+10;
struct node{
	int s,time;
}a[N][NN];
int c,n,m,d,q,t[N],u,v,k;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>t[i];
	}
	int minnumm=LONG_LONG_MAX;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=2*k;j++){
			if(j%2==1){
				cin>>a[i][j].s;
			}
			else{
				cin>>a[i][j].time;
				minnumm=min(a[i][j].time,minnumm);
			}
		}
	}
	if(n==2){
		for(int i=1;i<=q;i++){
			cin>>u>>v;
			int tt=0;
			for(int i=1;i<=NN;i++){
				if(a[1][i].s==0)break;
				if(a[1][i].s==u)tt++;
				if(a[1][i].s==v)tt++;
			}
			if(tt==2){
				cout<<t[u]+t[v];
			}
			else{
				cout<<t[u]+t[v]+minnumm;
			}
		}
	}
	return 0;
}
