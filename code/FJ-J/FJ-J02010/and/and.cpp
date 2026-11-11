#include<bits/stdc++.h>
using namespace std;
long long ans,f[200005],a[200005],vis[134217730];
int n,m,k,d,t;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	vis[2]=1;vis[4]=1;vis[8]=1;vis[16]=1;vis[32]=1;vis[64]=1;vis[128]=1;vis[256]=1;vis[512]=1;vis[1024]=1;
	vis[2048]=1;vis[4096]=1;vis[8192]=1;vis[16384]=1;vis[32768]=1;vis[65536]=1;vis[131072]=1;vis[262144]=1;
	vis[524288]=1;vis[1048576]=1;vis[2097152]=1;vis[4194304]=1;vis[8388608]=1;vis[16777216]=1;vis[33554432]=1;
	vis[67108864]=1;vis[134217728]=1;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(d==m)
			break;
		if(vis[a[i]]||a[i]==268435456||a[i]==536870912||a[i]==1073741824){
			f[++t]=a[i];
			continue;
		}
		if(!ans)
			ans=a[i];
		else
			ans&=a[i];
		d++;
	}
	if(d<m){
		for(int i=1;i<=t;i++){
			if(d==m)
				break;
			ans&=f[i];
			d++;
		}
	}
	printf("%lld",ans);
	return 0;
}
