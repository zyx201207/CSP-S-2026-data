#include<bits/stdc++.h>
using namespace std;
int t,c,n,a[2000005],b[2000005],e[2000005];
long long d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d%d%lld",&c,&t,&n,&d);
	while(t--){
		int sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			memset(b,sizeof(b),0);
			memset(e,sizeof(e),0);
			b[i]=1;
			for(int j=i;j<=n;j++){
				int x=i;
				for(;x<=j;x++){
					if(a[j]-a[x]<=d) break;
				}
				int y=x;
				for(;y<=j;y++){
					if(e[x]!=e[y]){
						y-=1;
						break;
					};
				}
				int maxn=b[y],t=0;
				for(int g=y;g>=x;g--){
					if(b[g]<maxn){
						break;
					}
					else t++;
				}
				cout<<t<<' ';
				b[j]=maxn*t;
				e[j]=e[x]+1;
				if(b[j]==2) sum++;
			}
		}
		printf("%d",sum);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
