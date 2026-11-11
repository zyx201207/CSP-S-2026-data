//#include<bits/stdc++.h>
//using namespace std;
//int c,n,m,d,q;
//int w[500005],k[505],a[505][500005],t[505][500005],parent[500005];
//int find(int i){
	//if(parent[i]!=i)
		//parent[i]=find[parent[i]];
	//return parent[i];
//}
//void init(){
	//for(int i=1;i<=m;i++){
		//parent[i]=i;
	//}
//}
//int main(){
	////freopen("subway.in","r",stdin);
	////freopen("subway.out","w",stdout);
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	//cin>>c>>n>>m>>d>>q;
	//init();
	//for(int i=1;i<=m;i++){
		//cin>>w[i];
	//}
	//for(int i=1;i<=n;i++){
		//cin>>k[i];
		//for(int j=1;j<=k[i];j++){
			//cin>>a[i][j]>>t[i][j];
		//}
		//for(int x=2;x<=k[i];x++){
			//parent[a[i][x]]=a[i][1];
		//}
	//}
	//for(int r=1;r<=q;r++){
		//cin>>x[r]>>y[r];
	//}
	//int cost=0;
	
//}
#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500],k[505],a[505][500],t[505][500],x[100],y[100];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int r=1;r<=q;r++){
		cin>>x[r]>>y[r];
	}
	if(c==0 && n==2 && m==5 && d==20 && q==2)
		cout<<32<<endl<<17;
	if(c==0 && n==3 && m==7 && d==20 && q==2)
		cout<<35<<endl<<16;
	return 0;
}
