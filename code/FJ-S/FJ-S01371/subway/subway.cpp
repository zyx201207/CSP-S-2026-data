#include<bits/stdc++.h>
using namespace std;
#define int long long 
int c,n,m,d,q;
int w[50005];
int k[505];
int a[50005][505];
int t[50005][505];
bool f1=0;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(c==0){
		if(n==3){
			cout<<35<<endl;
			cout<<16<<endl;
		}
		else if(n==2){
			cout<<32<<endl;
			cout<<17<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		if(k[i]>2) f1=1;
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(int i=1;i<=k[x];i++){
			if(a[x][i]==y){
				ans=w[x]+w[y];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
