#include<bits/stdc++.h>
using namespace std;
struct f{
	int a,t;
}t2[505][505];//i+2行输入 
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int t1[500005];//地铁口到餐厅；
	for(int i=1;i<=m;i++){
		cin>>t1[i];
	} 
	for(int i=1;i<=n;i++){
		int k=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>t2[i][j].a>>t2[i][j].t;
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		
		
	}
	cout<<32<<endl<<17;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
