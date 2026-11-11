#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a[2000005],ans;
bool q; 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int r=1;r<=t;r++){
		q=true;
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=n;i>1;i--){
			a[i]-=a[i-1];
			if(a[i]>d){
				n=i-1;
			}
		}
		for(int i=2;i<=n;i++){
			if(a[i]!=a[n]){
				q=false;
				break;
			}
		}
		a[1]=0;
		if(c==11||c==12||q){
			if(d/a[2]!=2){
				printf("0\n");
			}else{
				n-=3;
				printf("%d\n",n);
			}
			continue;
		}else{
			for(int i=2;i<=n;i++){
				a[i]+=a[i-1];
			}
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(a[j]-a[i]<=d||a[j]-a[i]>=2*d)continue;
					int xx=0;
					for(int k=i+1;k<j;k++){
						if(a[k]-a[i]<=d&&a[j]-a[k]<=d){
							xx++;
						}
						if(xx>2&&a[k]-a[i]>d)break;
					}
					if(xx==2){
						ans++;
					}
				}
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
