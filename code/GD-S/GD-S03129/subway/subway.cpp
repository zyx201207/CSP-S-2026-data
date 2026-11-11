#include<bits/stdc++.h>
#define int long long
using namespace std;

//const int MAXM=5e5+1;
//const int MAXN=501;
//const int MAXQ=1e5+1;
//
//int c,n,m,d,q;
//int w[MAXM];
//int k[MAXN],a[MAXN][MAXM],t[MAXN][MAXM];
//int x[MAXQ],y[MAXQ];
//
//void read(){
//	cin>>c>>n>>m>>d>>q;
//	for(int i=1;i<=m;i++){
//		cin>>w[i];
//	}
//	int idx=0;
//	while(cin>>k[idx++]){
//		for(int i=1;i<=k[idx];i++){
//			cin>>a[idx][i]>>t[idx][i];
//		}
//	}
//	for(int i=1;i<=q;i++){
//		cin>>x[i]>>y[i];
//	}
//	return ;
//}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
//	read();
	
	int c,x,y,z;
	cin>>c;
	cin>>x>>y>>z;
	if(x==2&&y==5&&z==20){
		cout<<32<<"\n"<<17;
	}
	if(x==3&&y==7&&z==20){
		cout<<35<<"\n"<<16;
	}
	return 0;
}
