#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500010];//m次 
int k[510];
int a[510][1010];//i经过j号地铁站 
int t[510][1010];//站厅到i号地铁线路的时间 
int r[500010];//1meidao,2 daole
int x[100010],y[100010];//始发站->终点站 
int zs=99999999;
void f(int e,int time,int v){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k[i];j++){
			if(r[a[i][j]]==2){
				return ;
			}
			if(a[i][j]==e){
				if(e==v){
					zs=min(zs,time+w[i]);
				}
				time+=t[i][j];
				r[a[i][j]]=2;
				f(a[i][j+1],time,v);
				f(a[i][j-1],time,v);
				r[a[i][j]]=1;
			}
		} 	
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c;
	cin>>n;//地铁线路数
	cin>>m;//地铁站数
	cin>>d;//每个地铁站最多被几条线路经过
	cin>>q;//出行计划数
	for(int i=1;i<=m;i++){
		cin>>w[i];//地铁口i到厅的时间 
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];//i经过di j号地铁站   站厅到i号地铁线路的时间
			r[a[i][j]]=1;
		}
	} 
	for(int i=1;i<=q;i++){
		cin>>x[i]>>y[i];
		f(x[i],w[i],y[i]);
		 cout<<zs;
	} 
	
	return 0;
} 


