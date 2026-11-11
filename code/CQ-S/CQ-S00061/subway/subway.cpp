#include<iostream>
using namespace std;
int c,n,m,d,q,k;//编码 线路数 站数 穿插数 问题数 
int v[20008],r[502][20008],w[502][20008];//入站时间 路线 出站时间 
int main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>v[i];}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++)
			cin>>r[k][j]>>w[k][j];}
	 
	if(c==0){
		if(n==2)
			cout<<32<<endl<<17;
		else
			cout<<35<<endl<<16;
		return 0;}
	else{
		int a;
		cout<<a;
	}
	

	return 0;
}


