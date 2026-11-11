#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q,a,s,e;
int w[500005],t[500005][600];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	//c分别表示测试点编号、n地铁线路数、m地铁站数、d每个地铁站最多被几条线路经过
	//q以及出行计划数
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a;
			cin>>t[a][i];
		}
	}
	if(m==1){
		for(int i=1;i<=q;i++){
			cout<<0;
		}
	}else if(m==2){
		int minn1=INT_MAX;
		for(int i=1;i<=n;i++){
			if(t[a][i]!=0) minn1=min(minn1,t[a][i]);
		}
		for(int i=1;i<=n;i++){
			cout<<minn1+w[1]+w[2];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s>>e;
		cout<<t[a][i]*2<<endl;
	}
	return 0;
}
//315275
//172.16.12.5
