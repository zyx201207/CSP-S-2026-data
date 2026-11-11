#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010];
long long fuled[50];
bool vis[200010];
long long ans;
int main(){
	freopen("and.in","r","stdin");
    freopen("and.out","w","stdout");
	scanf("%lld%lld",&n,&m);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		for(long long j=30;j>=0;j--){
			if((a[i]>>j)&1)fuled[j]++;
		}
	}
	for(long long i=30;i>=0;i--){
		if(fuled[i]<m)continue;
		long long cnt=0;
		for(long long j=1;j<=n;j++){
			if(vis[j])continue;
			if(((a[j]>>i)&1))cnt++;
		}
		if(cnt<m)continue;
		for(long long j=1;j<=n;j++){
			if(vis[j])continue;
			if(((a[j]>>i)&1)==0)vis[j]=true;
		}
		ans+=(1<<i);
	}
	printf("%lld",ans);
	return 0;
} 
