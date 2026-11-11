#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+5;
int n,m;
long long a[N];
int cnt[N][38];
bool vis[N];
bool flag[N];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		
		for(long long j=0;j<33;j++) {
			if(a[i]&(1ll<<j)) {
				cnt[i][j]=1;
			}
//			cout<<cnt[i][j]<<' ';
		}
//		cout<<'\n';
	}
//	cout<<'\n';
	
	long long ans=0;
	int sum=n-m;
	for(long long j=33;j>=0;j--) {
//		cout<<j<<'\n';
		bool ok=false;
		int k=0;
		int ip=0;
		
		for(int i=1;i<=n;i++) {
			if(!vis[i] && cnt[i][j]) {
				k++;
				ok=true;
				ip=i;
			}
		}
		
//		cout<<ok<<'\n';
		
		if(!ok) {
			continue;
		}
		
		int t=0;
		for(int i=1;i<=n;i++) {
			if(vis[i]) {
				continue;
			}
			
			if(cnt[i][j]) {
				continue;
			}
			
			if(flag[i]) {
				ok=false;
				break;
			}
			
			t++;
		}
		
		if(!ok) {
			continue;
		}
		
		if(t>sum) {
			ok=false;
			continue;
		}
		
		if(k==1) {
			flag[ip]=true;
		}
		sum-=t;
		
		for(int i=1;i<=n;i++) {
			if(vis[i]) {
				continue;
			}
			
			if(cnt[i][j]) {
				continue;
			}
			
			if(flag[i]) {
				ok=false;
				break;
			}
			
			vis[i]=true;
		}
		
//		cout<<ok<<' '<<sum<<'\n';
		
		if(ok) {
//			cout<<j<<' ';
			ans+=(1ll<<j);
		}
	}
	
	printf("%lld",ans);
	return 0;
}

/*
4 2
3 15 12 12\

5 3
31 3 1 15 7
*/
