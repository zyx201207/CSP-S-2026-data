#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[5000005],maxn=-1e9,ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i)continue;
				maxn=max(maxn,(a[i]&a[j]));
			}
		}
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+1+n);
	ans=a[n];
	for(int i=n-1;i>=n-m+1-1;i--){
		ans=(ans&a[i]);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
