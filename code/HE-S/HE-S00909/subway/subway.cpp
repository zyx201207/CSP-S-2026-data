#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,x,y,z;
	cin>>n>>m>>x>>y>>z;
	int a[1000]={0};
	int b[1000]={0};
	int c[1000]={0};
	int d[100]={0};
	int e[100]={0};
	int g[1000]={0};
	int f=1;
	while(f<=m){
		for(int i=1;i<=x;i++){
			cin>>a[i]>>b[i];
		}
		for(int i=1;i<=z;i++){
			cin>>g[i];
			for(int j=1;j<=g[i];j++){
				cin>>c[i];
			} 
		}
		for(int i=1;i<=2;i++){
			cin>>d[i]>>e[i];
		}
		
	}
	return 0;
}
