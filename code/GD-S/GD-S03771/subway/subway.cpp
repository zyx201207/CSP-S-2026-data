#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10,M=5e5+10;
ll n,m,w[N],c,d,q,k,mp[520][520],a[N],t[N],x[N],y[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=520;i++){
		for(int j=1;j<=520;j++){
			mp[i][j]=0;
		}
	}
	//邻接矩阵存每个点之间互通的是几号线 mp[i][j]指i点与j点互通的路线 
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<k;j++){
			for(int x=j+1;x<=k;x++){
				mp[a[j]][a[x]]=i;
				mp[a[x]][a[j]]=i;
			}
		}
	}
	for(int j=1;j<=q;j++){
		cin>>x[j]>>y[j];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){					
			cout<<mp[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
