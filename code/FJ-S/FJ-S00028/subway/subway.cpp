#include<bits/stdc++.h>
using namespace std;
int c,m,n,d,q,w[500005],t;
int a[501][500005],k[500005];
int  x,y,ti[501][500005];
struct e{
	int num;
	int v;
}r[501][501];
int main(){
	cin.tie(0);
//	freopen("subway1.in","r",stdin);
//	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>q;
	for(int i = 1;i<=n;i++){
		for(int j=1;j!= i && j<=n;j++){
			r[i][j].num=0x5f;
			r[j][i].num=0x5f;
		}
	}
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t;
			r[a[i][j-1]][j].num = 0;r[j][a[i][j-1]].num = 0;
			r[a[i][j-1]][j].v = i;r[j][a[i][j-1]].v = i;
			ti[a[i][j]][i] = t;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j = 1;j<=n &&j!=i;j++){
			for(int k=1;k<=n && k!=j &&k!=i;k++){
				if(r[i][k].v!=r[k][j].v){
					r[i][j].num = r[j][i].num=max(r[i][j].num,r[i][k].num+r[k][j].num+ti[k][r[i][k].v]+ti[k][r[k][j].v]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		cout<<r[x][y].num+w[x]+w[y]<<'\n';
	}
//	fclose(stdin);
//	fclose(stdout);
	return 0;
} 
