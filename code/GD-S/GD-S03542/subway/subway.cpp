#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
int a[505][50005];
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
			int x,t;
			cin>>x;
			cin>>t;
			a[i][x]=t;
		}
	}
	for(int i=1;i<=q;i++){
		int r,y;
		cin>>r>>y;
		long long ans=0;
		ans+=w[r]+w[y];
		for(int i=1;i<=n;i++){
			if(a[i][r]!=0){
				ans+=a[i][r];
			}
			if(a[i][y]!=0){
				ans+=a[i][y];
			}
		}
		cout<<ans;
	}
	return 0;
} 
