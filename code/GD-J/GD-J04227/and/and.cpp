#include <bits/stdc++.h>
using namespace std;
long long a[200010],f[200010];
long long ans=0;
bool ok[30];
long long n,m;
void dfs(long long now,long long anser){
	if(now==0){
		ans=max(ans,anser);
		return;
	}
	for(int i=1;i<=n;i++){
		if(ok[i]==0){
			ok[i]=1;
			dfs(now-1,anser&a[i]);
			ok[i]=0;
		}
	}
}
bool is(long long x){
	long long a=1;
	for(int i=1;i<=30;i++){
		a*=2;
		if(x==a-1)return 1;
	}
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)cin >> a[i];
	if(n<=2000){
		if(m==1){
			long long maxs=0;
			for(int i=1;i<=n;i++)maxs=max(maxs,a[i]);
			cout << maxs << endl;
			return 0;
		}
		if(m==n){
			long long axs=0;
			for(int i=1;i<=n;i++){
				axs&=a[i];
			}
			cout << axs << endl;
			return 0;
		}
		if(m==2){
			long long maxs=0;
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					if(i!=j){
						maxs=max(maxs,a[i]&a[j]);
					}
				}
			}
			cout << maxs << endl;
			return 0;
		}
		
	}
	if(n<=20){
		dfs(m,INT_MAX);
		cout << ans << endl;
		return 0;
	}
	
		if(m==n){
			long long axs=0;
			for(int i=1;i<=n;i++){
				axs&=a[i];
			}
			cout << axs << endl;
			return 0;
		}
	bool ok=1; 	
	for(int i=1;i<=n;i++){
		if(is(i)==0){
			ok=0;
			break;
		}
	}	
	if(ok){
		sort(a+1,a+n+1);
		cout << a[n-m+1] << endl;
	}	
	f[0]=LONG_LONG_MAX;
	for(long long i=1;i<=n;i++){
		for(long long j=m;j>=1;j--){
			f[j]=max(f[j],(f[j-1]&a[i]));
		}
	}
	cout << f[m] << endl;
} 
