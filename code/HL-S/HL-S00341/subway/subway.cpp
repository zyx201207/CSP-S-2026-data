#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5;
int w[M];
struct node{
	int a,t;
}sub[M];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;//d:最多被几条线路经过 m:站数 
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>sub[j].a>>sub[j].t;
		}
	}
	int cop;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(sub[i].a==sub[j].a){
				cop=sub[i].a;
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+sub[x].t+sub[y].t+w[y]<<endl;
	}
	
	return 0;
}
