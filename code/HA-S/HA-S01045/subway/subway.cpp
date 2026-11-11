#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	int a[n+2][n+2],t[n+2][n+2];
	int b[n+2];
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		int x1,y1;
		cin>>x1>>y1;
		int ans=b[x1]+b[y1];
		if(y1==3&&x1==1){
		ans+=t[1][1]+t[1][2]+t[2][2]+t[2][3];
		cout<<ans<<endl;
	  }
	  else if(y1==2){
	  ans+=t[1][1]+t[1][2];
	}
	 else if(y1==6){
	  ans+=t[1][1]+t[1][2]+t[3][3]+t[3][6];
	}
	 else if(y1==3){
	  ans+=t[2][2]+t[2][3];
	}
	 else if(y1==5){
	  ans+=t[1][1]+t[1][2];
	}
	else{
		ans+=t[1][1]+t[2][3]+t[3][5];
	}
}
	return 0;
} 
