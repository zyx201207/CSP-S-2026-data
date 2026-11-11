#include<bits/stdc++.h>
#define LL long long int 
using namespace std;
const int N=2e6+10,N1=5e3+10;
int c,n,ans;
LL d;
int f[N1][N1][2];
LL a[N];
void Main(){
	if(1<=c&&c<=25){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		ans=0;
		memset(f,0,sizeof f);
		for(int l=1;1+l<=n;l++){
			for(int i=1;i+l<=n;i++){
				int j=i+l;
				if(a[j]-a[i]<=d){
					f[i][j][1]=1;
					f[i][j][2]=1;
					continue;
				}
				f[i][j][2]=N;
				for(int k=i+1;k<j;k++){
					if(f[i][k][2]+f[k][j][2]<f[i][j][2]){
						f[i][j][2]=f[i][k][2]+f[k][j][2];
						f[i][j][1]=f[i][k][1]*f[k][j][1];
					}
					else if(f[i][k][2]+f[k][j][2]==f[i][j][2])
						f[i][j][1]+=f[i][k][1]*f[k][j][1];
				}
				if(f[i][j][1]==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T;
	scanf("%d%d",&c,&T);
	while(T--) Main();
	return 0;
}
