#include<bits/stdc++.h>
using namespace std;
int w[100000],k[600],a[1000][100000],t[1000][100000],min1=INT_MAX;
int qd,td;
bool dtz[10000];
void lx(int wz,int lx,int sj,bool zt){
	if(wz==td){
		min1=min(sj,min1);
		return ;
	}
	if(wz>k[lx]&&zt==1)return; 
	if(zt==1)
	if(wz>=zh)return;
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q; 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int i=1;i<=n;i++){
		cout<<a[i][j]<<t[i][j]; 
		}
	}
	for(int i=1;i<=q;i++){
		cin>>qd>>td;
		lx(qd,1,0,1);
	}
	return 0;
} 
