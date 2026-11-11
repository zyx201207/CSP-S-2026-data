#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,cnt=0,sum=0;
long long yyn[1000000];
bool nyy=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	for(int i=1;i<=b;i++){
		cnt=0;
		sum=0;
		nyy=0;
		scanf("%lld%lld",&c,&d);
		for(int j=1;j<=c;j++){
			scanf("%lld",&yyn[j]);
		}
		for(int k=1;k<=c;k++){
			e=k;
			e-=yyn[1];
			for(int o=1;o<k;o++){
				if(yyn[o+1]-yyn[o]>d){
					nyy=1;
				}
			}
			e/=d;
			if(e<=d&&nyy==0&&yyn[k]-yyn[1]>d){
				cnt++;
			}
		}
		printf("%lld\n",cnt);
	}
	return 0;
}
