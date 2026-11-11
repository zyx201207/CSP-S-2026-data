#include<bits/stdc++.h>
using namespace std;

const int N=2e6+10;
int ce,t,n,ans;
long long int d;
long long int x[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&ce,&t);
	while(t--){
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		if(ce==11||ce==12){
			long long int gongcha=x[2]-x[1];
			long long int num=d/gongcha;
			long long int ans=0;
			if(num==1||num==0){
				printf("0\n");
				continue;
			}
			for(int i=1;i<=n-num;i++){
				ans+=(n-i+1-gongcha)/gongcha;
			}
			printf("%lld\n",ans);
		}else if(ce==13||ce==14){
			long long int sum=0;
			for(int i=1;i<=n-1;i++){
				for(int j=i+1;j<=n;j++){
					if(x[i]-x[j]<=d)continue;
					for(int k=i;k<=j;k++){
						if(x[j]-x[k]>=d||x[k]-x[i]>=d)sum++;
					}
				}
			}
			printf("%lld\n",sum);
		}
	}
	return 0;
}
