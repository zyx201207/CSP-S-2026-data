#include<bits/stdc++.h>
using namespace std;
#define int long long
#define For(i,j,k) for(int i=(j);i<=(k);i++)
inline int read(){
	int ans=0,f=1;
	char c=getchar_unlocked();
	while(c<48||c>57){
		if(c=='-') f=-1;
		c=getchar_unlocked();
	}
	while(c>=48&&c<=57){
		ans=ans*10+c-48;
		c=getchar_unlocked();
	}
	return ans*f;
}
const int M=5010,inf=2e18+7;
int c,T,n,d,a[2000010],ans;
int f[M][M],g[M][M];
void init(){
	For(i,1,n){
		For(j,i,n) f[i][j]=1e9,g[i][j]=0;
	}
	ans=0;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read();d=read();
		
		bool flag=1;
		For(i,1,n){
			a[i]=read();
			if(i>2&&a[i]+a[i-2]!=2*a[i-1]) flag=0;
		}
		//~ For(i,2,n) printf("%lld ",a[i]-a[i-1]);
		//~ puts("");
		if(flag){
			int t=a[2]-a[1],p=d/t;
			//~ printf("%lld\n",d/t);
			if(p<=1) printf("0\n");
			else printf("%lld\n",max(0ll,n-2*p+1));
			continue;
		}
		
		init();
		For(len,2,n){
			For(i,1,n-len+1){
				int j=i+len-1;
				if(a[j]-a[i]<=d) {
					
					f[i][j]=g[i][j]=1;
					continue;
				}
				For(k,i+1,j-1){
					if(a[k]-a[i]<=d){
						if(f[i][j]>f[k][j]+1) f[i][j]=f[k][j]+1,g[i][j]=g[k][j];
						else if(f[i][j]==f[k][j]+1) g[i][j]+=g[k][j],g[i][j]=min(g[i][j],3ll);
					}
					else break;
				}
					
				if(g[i][j]==2){
					ans++;
					//~ printf("%lld %lld \n",i,j);
				}
			}
		}
		printf("%lld\n",ans);
		/*For(i,1,n){
			For(j,1,n){
				printf("%3lld",f[i][j]>=1e9?-1:f[i][j]);
			}
			puts("");
		}
		puts("");
		For(i,1,n){
			For(j,1,n){
				printf("%3lld",g[i][j]);
			}
			puts("");
		}*/
 	}
	return 0;
}
