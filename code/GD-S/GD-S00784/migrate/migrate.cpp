#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
long long c,t,total;
long long a[N];
long long n,d;
long long shortest=N,ans;
void dfs(long long start,long long stop,long long t){
	if(start==stop){
		if(shortest<t){
			shortest=t;
			ans=1;
			return ;
		}else if(shortest==t){
			ans++;
			return ;
		}
	}
	for(int i=1;i<=d;i++){
		if(start+d<=stop) dfs(start+d,stop,t+1);
		else return ;
	} 
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]); 
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				dfs(i,j,1);
				if(ans==2) total++;
				ans=0,shortest=0;
			}
		}
		printf("%ld\n",total);
		total=0;
	}
	return 0;
} 
