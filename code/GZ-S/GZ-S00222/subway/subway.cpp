//GZ-S00222 谭斯雨 贵阳市第一中学 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510;
int a[N][N],c,n,m,d,q,w[N],op[N],ln[N]; 
bool b[N][N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=INT_MAX;
		}
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		memset(op,0,sizeof(op));
		memset(ln,0,sizeof(ln));
		for(int j=1;j<=k;j++){
			cin>>op[j]>>ln[j];	
		}
		for(int j=1;j<=k;j++){
			for(int cl=1;cl<=k;cl++){
				a[op[j]][op[cl]]=min(a[op[j]][op[cl]],ln[j]+ln[cl]);
				b[op[j]][op[cl]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==1){
				continue;
			}
			else{
				for(int k=1;k<=j;k++){
					if(b[i][k]==1&&b[k][j]==1){
						a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
						a[j][i]=a[i][j];
						b[i][j]=b[j][i]=1;
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		int aka,gr;
		cin>>aka>>gr;
		cout<<a[aka][gr]+w[aka]+w[gr]<<endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 34 5 7
*/
