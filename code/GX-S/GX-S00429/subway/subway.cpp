#include<bits/stdc++.h>
using namespace std;
int w[500005],a[500005][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,k;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			int s;
			cin>>s;
			cin>>a[i][s]
		}
	}
	while(q--){
		int x,y,ans=0;
		cin>>x>>y;
		ans+=w[x]+w[y];
		int l,r;
		for(int i=0;i<n;i++){
			if(a[i][x]==0){
				continue;
			}else{
				int minx=999999;
				minx=min(minx,a[i][x]);
				ans+=minx;
				l=i;
			}
		}
		for(int i=0;i<n;i++){
			if(a[i][y]==0){
				continue;
			}else{
				int minx=999999;
				minx=min(minx,a[i][y]);
				ans+=minx;
				r=i
			}
		}
		int z;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[0][j]>0&&a[1][j]>0){
					int minj=j;
					minj=min(a[1][j],a[0][minj]){
					
					}
				}
				z=j;
			}
		}
		if(l!=r){
			ans+=a[0][j];
			ans+=a[1][j];
		}
		cout<<ans<<endl;
	}
	return 0;
}
