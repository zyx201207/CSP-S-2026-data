#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int z1[500005],k,z[505][500005],minn=100000000;
int x[500005],y[500005],ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int t;
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++){
		cin>>z1[i];
	}
	for(int i=0;i<n;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>t;
			cin>>z[t][i];
		}
	}
	for(int i=0;i<q;i++) cin>>x[i]>>y[i];
	for(int i=0;i<q;i++){
		ans=z1[x[i]]+z1[y[i]];
		if(x[i]>y[i]){
			int temp=x[i];
			x[i]=y[i];
			y[i]=temp;
		}
		for(int j=x[i];j<=y[i];j++){
			for(int k=0;k<n;k++){
				if(z[j][k]!=0){
					minn=min(minn,z[j][k]);	
				}
			}
			ans+=minn;
			minn=100000000;
		}
		cout<<ans<<endl;
	}
	return 0;
}

