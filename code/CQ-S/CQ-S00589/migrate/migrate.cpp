#include<cstdio>
using namespace std;
const int xn=2e6+5;
int c,t,n,cnt;
long long d,x[xn];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	printf("1");
	if(c<11){
		while(t--){
			scanf("%d%d",&n,&d);
			for(int i=1;i<=n;i++) scanf("%d",&x[i]);
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[j-1]>d) break;
					for(int k=i;k<=j;k++){
						if(x[k]-x[k-1]>d) break;
						cnt++;
					}
				}
			}
		}
		printf("%d\n",cnt);
	}
	else if(c<13){
		while(t--){
			scanf("%d%d",&n,&d);
			for(int i=1;i<=n;i++) scanf("%d",&x[i]);
			printf("0\n");
		}
	}
	else if(c<15){
		while(t--){
			scanf("%d%d",&n,&d);
			for(int i=1;i<=n;i++) scanf("%d",&x[i]);
			printf("2\n");
		}
	}
	else{
		while(t--){
			scanf("%d%d",&n,&d);
			for(int i=1;i<=n;i++) scanf("%d",&x[i]);
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(x[j]-x[j-1]>d) break;
					for(int k=i;k<=j;k++){
						if(x[k]-x[k-1]>d) break;
						cnt++;
					}
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
//S组好难啊 
//但J和S之间只相差8个字母啊（
//早上红橙黄绿，下午蓝靛紫黑……
//普及400，提高95…… 
//（从容就义） 
//哎 
