#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0' || c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=5005;
int c,T,n,p[N],f[N][N],t[N][N];
ll d,x[N];//? 2e18
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read();
		memset(t,0x3f,sizeof(t));
		for(int i=1;i<=n;i++){
			x[i]=read();
			t[i][i]=0,f[i][i]=1;
			for(int j=i-1;j;j--){
				if(x[i]-x[j]>d){
					break;
				}
				t[j][i]=1,f[j][i]=1;
			}
		}
		for(int l=2;l<=n;l++){
			for(int i=1;i+l-1<=n;i++){
				int j=i+l-1;
				for(int k=i+1;k<j;k++){
					if(t[i][k]==0x3fffffff && t[k][j]==0x3fffffff){
						continue;
					}
					if(t[i][j]>t[i][k]+t[k][j]){
						t[i][j]=t[i][k]+t[k][j];
						f[i][j]=f[i][k]*f[k][j];
//						f[i][j]+=(x[k]-x[i]<d)
//						if(i==1 && j==4) printf("%d %d %d\n",i,k,j);
					}else if(t[i][j]==t[i][k]+t[k][j]){
						f[i][j]+=f[i][k]*f[k][j];
//						printf("%d %d %d %d %d\n",i,k,j,f[i][k],f[k][j]);
					}
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			for(int j=1;j<=n;j++){
//				printf("%d ",f[i][j]);
//			}
//			printf("\n");
//		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(f[i][j]==2){
					cnt++;
				}
			}
		}
		printf("%d\n",cnt);
		for(int i=1;i<=n;i++){
			p[i]=0;
			for(int j=1;j<=n;j++){
				f[i][j]=0;
			}
		}
	}//gei le. bu hui. wo de dp shui ping apt.
	return 0;
}
