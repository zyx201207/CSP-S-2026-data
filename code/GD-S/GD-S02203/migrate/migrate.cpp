#include <bits/stdc++.h>
using namespace std;
int c,t;
const int N=2e6+10;
long long int n,d,a[N];
int check(int x,int y){
	int cur=0;
	if(a[x+1]-a[x]>d)return 0;
	if(y-x-1<2)return 0;
	for(int i=x;i<y;i++){
		if(a[i+1]-a[i]>d)return 0;
		if(a[i+1]-a[x]<=d)cur++;
	}if(cur==2)return 1;
	return 0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		long long int sum=0;
		for(int i=1;i<=n/2;i++){
			for(int j=i+3;j<=n;j++){
				sum+=check(i,j);
			}
		}
		printf("%lld\n",sum);
	}	
	return 0;
}
