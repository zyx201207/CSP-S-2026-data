#include<bits/stdc++.h>
using namespace std;
int c,n,m,D,q;
int point;
int t,b;
int d[1205][1205];
struct zhan{
	int num[505],cnt;
}a[505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	for(int i=1;i<=1200;i++){
		for(int j=1;j<=1200;j++){
			d[i][j]=1000000000;
		}
	}
	cin>>c>>n>>m>>D>>q;
	point=m;
	for(int i=1;i<=m;i++){
		int w;
		cin>>w;
		point++;
		d[i][point]=min(d[i][point],w);
		d[point][i]=min(d[point][i],w);
		a[i].num[++a[i].cnt]=point;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int B=-1;
		for(int j=1;j<=k;j++){
			cin>>b>>t;
			point++;
			d[a[b].num[1]][point]=min(d[a[b].num[1]][point],t);
			d[point][a[b].num[1]]=min(d[a[b].num[1]][point],t);
			a[b].num[i+1]=point;
			if(B!=-1) d[a[B].num[i+1]][a[b].num[i+1]]=d[a[b].num[i+1]][a[B].num[i+1]]=0; 
			B=b;
		}
	}
	for(int i=1;i<=point;i++){
		d[i][i]=0;
	}
	for(int k=1;k<=point;k++){
		for(int i=1;i<=point;i++){
			for(int j=1;j<=point;j++){
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<d[x][y]<<"\n";
	}
	return 0;
}
