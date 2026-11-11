#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<ctime>
#include<cstring>
#include<cstdio> 
#define int long long
#define INF 100000000000000
using namespace std; 
bool C[11];
int t,n,d,c;
int A[2000001],minn[11][11][2];
int read(){
	int sumer=0;
	int p=1;
	char ti;
	do{
		ti=getchar();
		if(ti=='-') p=-1;
		if(ti<='9'&&ti>='0') sumer=sumer*10+ti-'0';
	}while(ti=='-'||(ti<='9'&&ti>='0'));
	return sumer*p;
}
void solve(int x2){
	if(x2>n){
		int l=1010,r=1010,x=0,lst=0;
		for(int i=1;i<=n;i++){
			if(C[i]==1){
				r=i;
				if(l==1010)l=min(l,i);
				else{
					if(A[i]-A[lst]>d) return;
					else x++;
				}
				lst=i;
			}
		}
		if(l==1010||r==1010||l==r){
			return ;
		}
		if(x<minn[l][r][1]||minn[l][r][0]==0){
			minn[l][r][1]=x;
			minn[l][r][0]=1;
		}else if(x==minn[l][r][1]) minn[l][r][0]++;
		return ;
	}
	C[x2]=1;
	solve(x2+1);
	C[x2]=0;
	solve(x2+1);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();
	t=read();
	while(t--){
		memset(minn,0,sizeof(minn));
		n=read();
		d=read();
		for(int i=1;i<=n;i++) A[i]=read();
		solve(1);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(minn[i][j][0]==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*
мкршак 
*/
