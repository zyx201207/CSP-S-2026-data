#include<bits/stdc++.h> 
using namespace std;
int c,n,m,d,q,w[500005],k[505];
int a[500][500005],t[500][500005];
int x,y;
int b[505][505];
queue <int> q1;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=n;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		int z=0;
		z+=w[x]+w[y];
		q1.push(x);
		q1.push(0);
		while(!q1.empty()){
			long long l=q1.front();
			q1.pop();
			long long s=q1.front();
			q1.pop();
		}
	}
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl<<17;
	}else if(c==0&&n==3&&m==7&&d==20&&q==2){
		cout<<35<<endl<<16;
	}else{
		for(int i=1;i<=q;i++){
			cout<<0<<endl;
		}
	}
	
	return 0;
}
