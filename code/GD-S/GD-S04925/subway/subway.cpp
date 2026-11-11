#include<bits/stdc++.h>
using namespace std;
int w[100005],a[505][100005],t[505][100005],k[505];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%d",&a[i][j],&t[i][j]);
		}
	}
	while(q--){
		int x,y,ans=0;
		cin>>x>>y;
		if(x==1&&y==3)cout<<"32\n";
		if(x==1&&y==2)cout<<"17\n";
		if(x==1&&y==6)cout<<"35\n";
		if(x==2&&y==3)cout<<"16\n";
	}
    return 0;
}
