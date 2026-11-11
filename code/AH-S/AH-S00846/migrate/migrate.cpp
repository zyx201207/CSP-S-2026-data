#include<bits/stdc++.h>
using namespace std;
int n,a[2000005],b[2000005];
long long x[2000005],cntl[2000005],cntr[20000005],cntx[2000005],cnty[2000005],d,pp;
bool vis[2000005];
int lreach(int xx,long long p){
	int l = 1,r = xx;
	while(l < r){
		int mid = (l + r) / 2;
		if(x[mid] >= p) r = mid;
		else l = mid + 1;
	}
	if(l == xx) return 0;
	return l;
}
int rreach(int xx,long long p){
	int l = xx,r = n;
	while(l < r){
		int mid = ceil((l + r) / 2.0);
		if(x[mid] <= p) l = mid;
		else r = mid - 1;
	}
	if(l == xx) return 0;
	return l;
}
void dfsl(int pos,int cnt){
	if(!a[pos]) return;
	vis[pos] = 1;
	if(a[pos] > 1) cntx[pos] += cnt * cntl[a[pos] - 1];
	dfsl(a[pos],cnt + 1);
}
void dfsr(int pos,int cnt){
	if(!b[pos]) return;
	vis[pos] = 1;
	if(b
	[pos] < n) cnty[pos] += cnt * cntr[b[pos] + 1];
	dfsr(b[pos],cnt + 1);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(cntl,0,sizeof(cntl));
		memset(cntr,0,sizeof(cntr));
		memset(cntx,0,sizeof(cntx));
		memset(cnty,0,sizeof(cnty));
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(x,0,sizeof(x));
		scanf("%d %lld",&n,&d);
		for(int i = 1;i <= n;i++) scanf("%lld",&x[i]);
		for(int i = 1;i < n;i++) a[i] = rreach(i,x[i] + d),cntr[a[i]]++;
		for(int i = 2;i <= n;i++) b[i] = lreach(i,x[i] - d),cntl[b[i]]++;
		//for(int i = 1;i <= n;i++) cout<<lreach(i,x[i] - d)<<" ";
		//cout<<endl;
		//for(int i = 1;i <= n;i++) cout<<rreach(i,x[i] + d)<<" ";
		//cout<<endl;
		long long ans = 0;
		for(int i = 1;i <= n;i++) if(!vis[i]) dfsl(i,1);
		memset(vis,0,sizeof(vis));
		for(int i = n;i >= 1;i--) if(!vis[i]) dfsr(i,1);
		memset(vis,0,sizeof(vis));
		for(int i = 1;i <= n;i++){
			//cout<<cntx[i]<<" "<<cnty[i]<<endl;
			if(a[i] && a[i] - 1 > i && a[i] - 1 >= 1 && a[a[i] - 1] <= n && a[a[i] - 1] > a[i]) ans += cntx[i] * cnty[a[a[i] - 1]];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
