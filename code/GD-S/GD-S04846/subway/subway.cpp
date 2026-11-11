#include<bits/stdc++.h>
using namespace std;
long long c,n,m,h,q,w[1000005],k,a[1000005],t[1000005],d[2005][2005],st,en;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>h>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<=k;j++){
			for(int p=j+1;p<=k;p++){
				d[a[j]][a[p]]=min(d[a[j]][a[p]],t[j]+t[p]);
				d[a[p]][a[j]]=min(d[a[p]][a[j]],t[j]+t[p]);
			}
		}
	}
	for(int o=1;o<=m;o++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i!=j)d[i][j]=min(d[i][j],d[i][o]+d[o][j]);
			}
		}
	}
	while(q--){
		cin>>st>>en;
		cout<<w[st]+w[en]+d[st][en]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
