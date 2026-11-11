#include<bits/stdc++.h>
using namespace std;
struct stu{
	long long c[60];
	long long n;
};
stu a[2000005];
long long tmpp[60];
long long vis[60];
long long INF = 99999999;
void ca(long long maxm,long long n){
	long long ans = 0;
	for(long long i = 1;i <= maxm;i++){
		bool b = 1;
		for(long long j = 1;j <= n;j++){
			if(vis[j] == INF){
				continue;
			}
			if(a[j].n < i) b = 0;
			b &= a[j].c[i];
		}
		ans += b * pow(2,i - 1);
	}
	cout<<ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long maxn = 0;
	for(long long i = 1;i <= n;i++){
		long long tmp;
		cin>>tmp;
		memset(tmpp,0,sizeof(tmpp));
		while(tmp){
			a[i].n++;
			tmpp[a[i].n] = tmp % 2;
			tmp /= 2;
		}
		for(long long j = a[i].n;j >= 1;j--){
			a[i].c[j] = tmpp[j];
		}
		maxn = max(maxn,a[i].n);
	}
	long long maxm = maxn;
	memset(vis,0,sizeof(vis));
	long long nn = n;
	while(maxn > 0){
		int long long cnt = 0;
		for(long long i = 1;i <= n;i++){
			if(a[i].n < maxn || vis[i] == INF) continue;
			if(a[i].c[maxn]) cnt++;
		}
		if(cnt >= m){
			for(long long i = 1;i <= n;i++){
				if(a[i].n < maxn && vis[i] != INF){
					vis[i] = INF;
					continue;
				}
				if(!a[i].c[maxn]){
					vis[i] = INF;
				}
			}
			nn = cnt;
		}
		if(cnt == m){
			ca(maxm,n);
			return 0;
		}
		maxn--;
	}
	bool w = 1;
	for(long long i = 1;i <= n;i++){
		if(vis[i] == INF){
			w = 0;
			break;
		}
	}
	if(w && n != m){
		cout<<0;
	}else{
		long long cz = 0;
		for(long long i = 1;i <= n;i++){
			if(vis[i] == INF) continue;
			if(cz == m){
				vis[i] = INF;
			}
			if(cz < m){
				cz++;
			}
		}
		ca(maxm,n);
	}
	return 0;
}
