#include <bits/stdc++.h>
using namespace std;
long long n,m,a[300000];
long long maxn=-1e9;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	if(n<=20&&m<=n){
		int cnt=0;
		for(long long i=1;i<=m;i++){
			int x;
			for(long long j=i;j<=n;j++){
				for(long long z=j;z<=n;z++){
					maxn=max(maxn,a[i]&a[j]);
				}
			}
		}
			
	}		
	if(n<=2000&&m==1){
		for(long long i=1;i<=n;i++)maxn=max(maxn,a[i]);
	}
	if(n<=2000&&m==n){
		long long cnt=a[1]&a[2];
		for(long long i=3;i<=n;i++){
			cnt=cnt+cnt&a[i];
		}
		maxn=cnt;
	}
	if(n<=2000&&m==2){
		int cnt=0;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
	}		
	cout<<maxn;
	return 0;
}
