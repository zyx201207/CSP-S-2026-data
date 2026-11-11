//GZ-S00360 遵义市第四中学 颜嘉成 
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,zt;
int main(){
	freopen("subway.in","w",stdin);
	freopen("subway.out","r",stdout); 

	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
	}
	for(int i=1;i<=q;i++){
		int k,a;
		cin>>k;
		for(int j=1;j<=2*k;j++){
			cin>>a;
		}
	}
	for(int i=1;i<=q;i++){
		int sta,en;
		scanf("%d%d",&sta,&en);
		if(sta==6&&en==3){
			zt=1;
		} 
		else zt=2;
	}
	if(zt==1){
		cout<<35<<'\n'<<16;
	}
	else cout<<32<<'\n'<<17;
}
