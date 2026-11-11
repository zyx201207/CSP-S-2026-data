#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[125255],a[505][505],t[505][505],k[505],ans[50005];
int main(){
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x,y,tot=0;
		cin>>x>>y;
		int nowx,nowy,gox,goy,wcd[505][505];
		for(int j=1;j<=k[i];j++){
			for(int k=1;k<=n;k++){
				if(a[k][j]==x){
					nowy=j;
					nowx=i;
				}if(a[k][j]==y){
					goy=j;
					gox=i;
				}
				for(int u=1;u<=n;u++){
					if(a[i][j]==a[i+u][j]){
						wcd[i][u]=j;
					}
				}
			}
		}
		if(nowx==gox){
			int b=max(nowy,goy),s=min(nowy,goy);
			tot=tot+w[goy]+w[nowy];
			for(int j=s;j<=b;j++){
				tot+=t[nowx][j];
			}
		}else{
			tot+=(w[nowx]+w[gox]);
			while(goy!=nowy||gox!=nowx){
				int togo=wcd[gox][nowx];
				int b=max(nowy,togo),s=min(nowy,togo);
				for(int j=s;j<=b;j++){
					tot+=t[nowx][j];
				}
				nowx=gox;
				if(nowx==gox){
					b=max(nowy,goy),s=min(nowy,goy);
					for(int j=s;j<=b;j++){
						tot+=t[nowx][j];
					}
				}
			}
		}
		ans[i]=tot;
	}
	for(int i=1;i<=q;i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}
