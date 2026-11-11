#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],k[505],a[505][50005],t[505][50005],x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		long long sum=0,jj=0;
		sum+=w[x];
		sum+=w[y];
		for(int j=1;j<=n;j++){
			for(int l=1;l<=k[j];l++){
				if(a[j][l]==x){
					sum+=t[j][l];
					jj++;
					if(jj==2){
						break;
					}
				}
				if(a[j][l]==y){
					sum+=t[j][l];
					jj++;
					if(jj==2){
						break;
					}
				}
			}
			if(jj==2){
				break;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
