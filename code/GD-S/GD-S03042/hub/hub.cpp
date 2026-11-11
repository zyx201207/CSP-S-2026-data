#include<bits/stdc++.h>
using namespace std;
using ll= long long;
const int N=2e2+2;
using namespace std;
int c,n,m,d,q;
ll w[N];
ll dis[N][N];
int a[N][N];
int main(){
	cout <<dis[0][0];
	cin >> c >> n >>m>>d>>q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		int k,cnt=0;
		cin >> k;
		for(int j=1;j<=k;++j){
			int x,y;
			cin >> x >> y;
			a[++cnt][0]=x;
			a[cnt][1]=y;
		}
		for(int j=1;j<=cnt;++j){
		    for(int k=j+1;k<=cnt;k++){
			    if(j==k) continue;
			    int x=a[j][0] ,y=a[k][0];
		    }
	    }
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;j++){
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin >> x >>y;
		cout << w[x]+w[y]+dis[x][y]<<endl;
	}
	return 0;
}


