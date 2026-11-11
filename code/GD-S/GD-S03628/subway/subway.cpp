#include<bits/stdc++.h>
using namespace std;
int sj,c,n,m,d,q,w[50005],z,tong[50005],x[100005],y[100005],k[50005],t[50005],a[50005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		z=k[i];
		for(int j=1;j<=z;j++){
			cin>>a[i+j]>>t[i+a[i+j]];
			tong[a[i+j]+i]++;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		sj+=w[x[i]]+w[y[i]];
		for(int j=1;j<=n;j++){
			if(tong[x[i]+j]){
				sj+=t[j+i];
			}
		}
		cout<<sj;
		sj=0;
	}
	
	return 0;
} 
