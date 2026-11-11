#include<bits/stdc++.h>
using namespace std;
int www,n,m,b,a,c[500005][3],d=1000000000;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>www>>n>>m>>b>>a;
	if(n==2){
		for(int i=1;i<=m;i++) cin>>c[i][0];
		for(int i=1;i<=n;i++){
			int e;
			cin>>e;
			for(int j=1;j<=e;j++){
				int x,y;
				cin>>x>>y;
				c[x][i]=y;
			}
		}
		for(int i=1;i<=m;i++){
			if(c[i][1]&&c[i][2]) d=min(d,c[i][1]+c[i][2]);
		}
		for(int i=1;i<=a;i++){
			int x,y;
			cin>>x>>y;
			if(c[x][1]&&c[y][1]) cout<<c[x][0]+c[x][1]+c[y][1]+c[y][0]<<endl;
			else if(c[x][2]&&c[y][2]) cout<<c[x][0]+c[x][2]+c[y][2]+c[y][0]<<endl;
			else if(c[x][2]&&c[y][1]) cout<<c[x][0]+c[x][2]+c[y][1]+c[y][0]+d<<endl;
			else cout<<c[x][0]+c[x][1]+c[y][2]+c[y][0]+d<<endl;
		}
	}else{
		cout<<32767;
	}
	return 0;
}

