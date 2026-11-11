#include<bits/stdc++.h>
using namespace std;

int c,n,m,d,q;
int ln[2001][2];//floyed超过1e3就可以等掉了，没必要开更大！ 
int fl[2001][2001];
int v[2001];

int ck(int a,int b){
	if(b<a)return ck(b,a);
	else return fl[a][b];
}

void fz(int a,int b,int num){
	num=min(ck(a,b),num);
	if(b<a)fl[b][a]=num;
	else fl[a][b]=num;
}

int main(){
	for(int i=1;i<=2000;i++)for(int j=1;j<=2000;j++)fl[i][j]=998244353;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if(false){
		return 0;//5e5无法floyed 
	}
	for(int i=1;i<=m;i++)cin>>v[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>ln[j][0]>>ln[j][1];
		}
		for(int l=1;l<=k;l++){
			for(int j=l;j<=k;j++){
				fz(ln[l][0],ln[j][0],ln[l][1]+ln[j][1]);
			}
		}
	}
	//(int k=1;k<=m;k++)
	//(int i=1;i<=m;i++)
	//(int j=i;j<=m;j++)
	for(int i=1;i<=m;i++){
		for(int k=1;k<=m;k++){
			for(int j=i;j<=m;j++){
				fz(i,j,ck(i,k)+ck(j,k));
			}
		}
	}
	for(int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		cout<<ck(a,b)+v[a]+v[b]<<'\n';
	}
}
