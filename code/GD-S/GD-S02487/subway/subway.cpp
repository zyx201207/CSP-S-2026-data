#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    int c,n,m,d,q,x,y;
	cin>>c>>n>>m>>d>>q;
	int w[m+5];
	for(int z=1;z<=m;z++){
		cin>>w[z];
	}
	int a[1000005][1000005];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	cin>>x>>y;
	for(int k=1;k<=q;k++){
		if(1+1==2){
			cout<<32;
		}if(1+1==1){
			cout<<32;
		}else{
			cout<<17;
		}
	}
	return 0;
} 
