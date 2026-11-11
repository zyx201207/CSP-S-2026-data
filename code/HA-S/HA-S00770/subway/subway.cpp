#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,w[100005],k[100005],a[100005][100005],t[100005][100005],x[100005],y[100005];
	int p=0,o=0;
	cin>>c>>n>>m>>d>>q;
	
	for(int i=m;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
	}
	while(q--){
		int shijian=0,kai=0;
		for(int i=1;i<=n;i++){
			p=0;
			o=0;
			for(int j=1;j<=k[i];j++){
				if(a[i][j]==x[1]){
					p=1;
				}
				if(a[i][j]==y[1]){
					o=1;
				}
			}
			if(n==2 and p==o and p==1){
				for(int b=1;b<=k[i];b++){
					if(a[i][b]==x[1]){
						shijian+=w[x[1]];
						kai=1;
					}
					if(kai==1){
						shijian+=t[i][a[i][b]];
					}
					if(a[i][b]==y[1]){
						shijian+=w[y[1]];
					}
				}
				cout<<shijian<<'\n';
				
			}
		}
		
	}
	
	return 0;
}
