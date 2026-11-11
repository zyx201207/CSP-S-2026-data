#include<bits/stdc++.h>
using namespace std;
const int N=50005,P=pow(2,62)-1;
int rans,c,n,m,d,q,a1[500][N],a2[500][N],t[1005][1005]={P},t1[1005][1005],gh[N];
bool im[50005];
void  dg(int  now,int  end,int  nans,int lasl,int las){
	if(now==end){
		rans=min(rans,nans);
		return ;
	}
	for(int  i=1;i<=m;i++){
		if(t[i][now]==P||im[i]==1||i==now)continue;
		im[i]=1;
		int x=nans+t[i][now];
		if(t1[i][now]==lasl)x-=las;
		dg(i,end,x,t1[i][now],t[i][now]);
		im[i]=0;
	}
	return ;
}
void p1(){
	while(q--){
		int x,y;
		cin>>x>>y;
		rans=0;
		dg(x,y,0,0,0);
		cout<<rans+t[x][x]+gh[x]+gh[y]<<endl;
	}
	
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			t[i][j]=P;
		}
	}
	for(int i=1;i<=m;i++)cin>>gh[i];
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		for(int j=1;j<=l;j++){
			cin>>a1[i][j]>>a2[i][j];
		}
		for(int j=1;j<=l;j++){
			for(int h=1;h<=l;h++){
				t[a1[i][h]][a1[i][j]]=min(t[a1[i][h]][a1[i][j]],a2[i][h]);
				t1[a1[i][h]][a1[i][j]]=i;
			}
		}
	} p1();
	return 0;
} 
//0 3 7 20 2
//8 3 6 1 7 2 9
//3 1 4 2 5 5 100
//3 2 6 3 1 7 2
//4 3 2 5 100 4 6 6 7
//1 6
//2 3
