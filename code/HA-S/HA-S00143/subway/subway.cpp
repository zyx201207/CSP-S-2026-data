#include <bits/stdc++.h>
using namespace std;
int n,m,c,d,q,w[500005],x[100005],y[100005],a[505][500005],t[505][500005],k[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>a[i][j]>>t[i][j];
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=q;i++){
		int xi1=0,yi1=0,xi2=0,yi2=0;
		for(int j=1;j<=n;j++){
			for(int f=1;f<=k[j];f++){
				if(a[j][f]==x[i]){
					xi1=j;
					yi1=f;
				}
			}
			for(int f=1;f<=k[j];f++){
				if(a[j][f]==y[i]){
					xi2=j;
					yi2=f;
				}
			}
		}
		int sum=0;
		sum+=w[x[i]];
		sum+=w[y[i]];
		int xjj=0,yjj=0;
		for(int j=1;j<n;j++){
			for(int f=1;j<=k[j];f++){
				for(int g=1;g<=k[j+1];g++){
					if(a[j][f]==a[j][g]){
						sum+=t[j][f];
						xjj=j;
						yjj=g;
					}
				}
			}
		}
		sum+=t[xjj][yjj];
		cout<<sum<<endl;
		//cout<<xi1<<" "<<yi1<<"---"<<xi2<<" "<<yi2<<endl;
	}
	return 0;
}

