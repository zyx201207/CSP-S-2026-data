#include<bits/stdc++.h>
using namespace std;
int cc,t;
long long g[10001][10001];
long long d;
long long v;
long long k;
long long vis[100001];
void f(int a,int b,int c,int e){
	if(vis[a]==1){
		return;
	}
	if(a==b){
		
		if(c<d){
			d=c;
			v=2;
		}
		if(c==d){
			v+=1;
		return;
	}
	vis[a]=1;
	
	for(int i=1;i<=e;i++){
		if(g[a][i]){
			f(i,b,c+1,e);
			
		}
	}
}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>cc>>t;
	for(int i=1;i<=t;i++){
		k=0;
		long long n,dd;
		cin>>n>>dd;
		long long x[100001];
		for(int i=1;i<=n;i++){
			cin>>x[i];
			for(int j=1;j<i;j++){
				if(abs(x[i]-x[j])<=dd){
					g[j][i]=1;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				d=100000;
				v=0;
				memset(vis,0,sizeof(vis));
				f(i,j,0,n);
				if(v==2){
					k++;
				}
				
			}
		}
		cout<<k<<endl;
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
