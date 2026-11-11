#include<bits/stdc++.h>
using namespace std;
int c,t;
long long x[2000002],n,d,sum=0,l,le,q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	for(int i=0;i<t;i++){
		sum=1;
		scanf("%lld%lld",&n,&d);
		for(int j=0;j<n;j++){
			scanf("%lld",&x[j]);
		}
		for(int u=0;u<n-1;u++){
			for(int v=u+1;v<n;v++){
				le=1;
				q=u;
				l=1;
				for(int k=u+1;k<=v;k++){
					if(x[k]-x[q]<=d&&x[k+1]-x[q]>d&&k+1<=v){
						q=k;
						le++;
					}
					if(x[k]-x[q]<=d){
						l++;
					}
				}
				if(l-le==3)sum++;
			}
		}
		printf("%lld\n",sum);
	}
}
