#include<bits/stdc++.h>
using namespace std;
int c,n,m,mv[500001],d,q,x,y,tim=0;
long long route[2][500001],min1[2];
struct way{
	int k;
	int a[500001];
	int t[500001]; 
}way[501];
struct way1{
	int a,b;
	long long ti;
}way1[1000001];
int main(){
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++){
		cin >>mv[i];
	}
	for(int i=1;i<=n;i++){
		cin >> way[i].k;
		printf("%d ",way[i].k);
		for(int j=1;j<=way[i].k;j++){
			cin >> way[i].a[j] >> way[i].t[j] ;
		}
	}
	int p=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=way[i].k-1;j++){
			for(int l=j+1;l<=way[i].k;l++){
				p++;
				way1[p].a=way[i].a[j];
				way1[p].b=way[i].a[l];
				way1[p].ti=way[i].t[j]+way[i].t[l]; 
			}
		}
	}
	for(int i=1;i<=q;i++){
		for(int j=1;j<=m;j++){
			route[1][j]=1e16;
			route[0][j]=0;
		}
		cin >>x >> y;
		tim+=mv[x]+mv[y];
		route[1][x]=0;
		route[0][x]=1;
		min1[1]=x;
		min1[2]=0;
		for(int j=1;j<=m;j++){
			for(int l=1;l<=p;l++){
				if(way1[l].a==min1[1]&&route[0][way1[l].b]==0){
					route[1][way1[l].b]=min(way1[l].ti+min1[2],route[1][way1[l].b]);
				}
				else if(way1[l].b==min1[1]&&route[0][way1[l].a]==0){
					route[1][way1[l].a]=min(way1[l].ti+min1[2],route[1][way1[l].a]);
				}
			}
			min1[2]=1e16;
			for(int l=1;l<=m;l++){
				if(route[1][l]<min1[2]&&route[0][l]==0){
					min1[1]=l;min1[2]=route[1][l];
				}
			}
			if(min1[1]==y){
				cout << route[1][y];
				break;
			}
			route[0][min1[1]]=1;
		}
	}
	
	return 0;
}
