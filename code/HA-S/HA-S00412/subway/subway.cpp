#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans=0;
int w[50000],k;
struct qs{
	int x,y;
}bh[10005];
int a[2005][5005],t[2005][5005];
int fat[1005];
int find(int x){
	if(fat[x]!=x) fat[x]=find(fat[x]);
}
void unionn(int x,int y){
	int r1=find(x);
	int r2=find(y);
	if(r1!=r2) fat[r2]=r1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int j=1;j<=m;j++){
		fat[j]=j;
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		int l;
		for(int j=1;j<=k;j++){
			cin>>a[k][j]>>t[k][j];
			if(j==1) unionn(l,a[k][j]);
			if(j>=2&&j!=k){
				unionn(a[k][j],a[k][j-1]);
			}
			else if(j==k){
				l=a[k][j];
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>bh[i].x>>bh[i].y;
		ans+=w[bh[i].x];
		int h=fat[bh[i].y];
		if(h!=bh[i].x){
			ans+=t[i][h];
			h=find(h);
		}
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
