#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int cnt[33];
int ans,res;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i]; 
	sort(a+1,a+1+n);
	if(m==1){
		cout << a[n];
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout << ans;
		return 0;
	}
	else if(n<=20){
		for(int s=1;s<(1<<n);s++){
			ans=0;
			memset(cnt,0,sizeof(cnt));
			if(__builtin_popcount(s)!=m) continue;
			for(int i=0;i<n;i++){
				if(s&(1<<i)){
					for(int j=0;j<=30;j++){
						if(a[i+1]&(1<<j)) cnt[j]++;
					}
				}
			}
			for(int i=0;i<=30;i++){
				if(cnt[i]==m){
					ans+=(1<<i);
				}
			}
			res=max(res,ans);
		}
		cout << res;
		return 0;
	}
	else if(m==n){
		for(int i=1;i<=n;i++){
			for(int j=0;j<=30;j++){
				if(a[i]&(1<<j)) cnt[j]++;
			}
		}
		for(int i=0;i<=30;i++){
			if(cnt[i]==m){
				ans+=(1<<i);
			}
		}
		cout << ans;
		return 0;
	}
	else{
		cout << a[1];
		return 0;
	}
	return 0;
}
