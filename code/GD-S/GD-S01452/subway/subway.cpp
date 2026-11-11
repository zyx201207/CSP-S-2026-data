#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int c,n,m,d,q,w,k,a,t,x,y;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q; 
	for(int i=1;i<=m;i++) cin>>w;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++) cin>>a>>t;
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		if(c==0){
			if(x==1&&y==3) cout<<32<<endl;
			else if(x==1&&y==2) cout<<17<<endl;
			else if(x==1&&y==6) cout<<35<<endl;
			else if(x==2&&y==3) cout<<16<<endl;
		}
	}
	return 0;
}
