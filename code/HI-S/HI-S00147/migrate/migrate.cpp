#include<bits/stdc++.h>
using namespace std;
const int MAXN=300;
int c,T,n,d,ans,x[MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	for(int te=1;te<=T;te++){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&x[i]);
		}
		ans=0;
		int step=floor(d/(x[2]-x[1]));
		if(step==1){
			printf("0\n");
			continue;
		}
		for(int i=1;i<n-step;i++){
			for(int j=min(i+step+1,n);j<=n;j++){
				if((j-i)%step==1)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
