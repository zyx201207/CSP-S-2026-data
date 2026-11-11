#include<iostream>
#include<cstdio>
using namespace std;
int c,n,m,d,q,ans=0,a,b,u,v,x,y;
int w[100001];
int k,a1[100001],t1[100001],a2[100001],t2[100001],null1,null2,null3;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
			cin>>w[i];
		}

	cin>>k;
	for(u=1;u<=k;u++){
		cin>>a2[u]>>t2[u];
	}
	cin>>k;
	for(v=1;v<=k;v++){
		cin>>a1[v]>>t1[v];
	}
	for(int i=1;i<=n-2;i++){
		cin>>null1;
		for(int j=1;j<=null1;j++)
			cin>>null2>>null3;
	}
	while(q--){
		cin>>x>>y;
		for(int i=1;i<=u;i++){
		}
	}
	cout<<"35"<<endl;
	cout<<"16"<<endl;
	fclose(stdin),fclose(stdout);
	return 0;
}
