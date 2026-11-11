//GZ-s00382 Ã∑‚˘≈Ù  
#include<bits/stdc++.h>
using namespace std;
long long s=0,c,n,m,d,q,a[210][410],cb[210][410],ko[410];
void sb(int qd,int zd,int ms){
	if(qd==zd){
		if(s==0)s=ms;
		if(s>ms){
			m=ms;
		}
		return ;
	}
	for(int x=1;x<=n;x++){
		if(a[x][qd]!=0){
			for(int y=1;y<=m;y++){
				if(a[x][y]!=0 && y!=qd && cb[x][y]==0){
					cb[x][y]=1;
					sb(y,zd,ms+a[x][y]+a[x][qd]);
					cb[x][y]=0;
				}
			}
		}
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int x=1;x<=m;x++)cin>>ko[x];
	for(int x=1;x<=n;x++){
		int k;cin>>k;
		for(int y=0;y<k;y++){
			int v;cin>>v;
			cin>>a[x][v];
		}
	}
	for(int x=0;x<q;x++){
		s=0;
		for(int i=0;i<=200;i++){
			for(int j=0;j<410;j++){
				cb[i][j]=0;
			}
		}
		int qdd,zdd;cin>>qdd>>zdd;
		sb(qdd,zdd,0);
		s+=ko[qdd];
		s+=ko[zdd];
		cout<<s;
	}
	return 0;
} 
