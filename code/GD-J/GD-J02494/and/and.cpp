#include<bits/stdc++.h>
using namespace std;

long long n,m,ans=0;
long long a[200010];

map<long long,bool>mp;
void init(){
	mp[ 1 ]=true;
	mp[ 2 ]=true;
	mp[ 4 ]=true;
	mp[ 8 ]=true;
	mp[ 16 ]=true;
	mp[ 32 ]=true;
	mp[ 64 ]=true;
	mp[ 128 ]=true;
	mp[ 256 ]=true;
	mp[ 512 ]=true;
	mp[ 1024 ]=true;
	mp[ 2048 ]=true;
	mp[ 4096 ]=true;
	mp[ 8192 ]=true;
	mp[ 16384 ]=true;
	mp[ 32768 ]=true;
	mp[ 65536 ]=true;
	mp[ 131072 ]=true;
	mp[ 262144 ]=true;
	mp[ 524288 ]=true;
	mp[ 1048576 ]=true;
	mp[ 2097152 ]=true;
	mp[ 4194304 ]=true;
	mp[ 8388608 ]=true;
	mp[ 16777216 ]=true;
	mp[ 33554432 ]=true;
	mp[ 67108864 ]=true;
	mp[ 134217728 ]=true;
	mp[ 268435456 ]=true;
	mp[ 536870912 ]=true;
}

void dfs(long long step,long long re,long long cnt){
	if(step>n){
		if(cnt==m)ans=max(ans,re);
		return;
	}
	if(cnt!=m){
		dfs(step+1,re&a[step],cnt+1);
	}
	dfs(step+1,re,cnt);
}
int main(){
	init();
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%lld %lld",&n,&m);
	
	bool fA=true;
	
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		fA&=mp.count(a[i]+1);
	}
	if(fA){
		sort(a+1,a+n+1);
		printf("%lld",a[n-m+1]);
		return 0;
	}
	
	dfs(1,1073741823,0);
	printf("%lld",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

