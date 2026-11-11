#include<bits/stdc++.h>
using namespace std;
long long r=1,l=1,n,m,a[1000001],sum,b[1000001],mid;
int ans=-1;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(m>=100000000) {
		b[1]=0;
		for(int i=2;i<=n;i++) b[i]=b[i-1]+i-1;
		for(int i=1;i<=n;i++){
			if(b[i]<=m){
				ans=i;
			}
			else break;
		} 
		cout<<ans;
		return 0;
	} else {
		sort(a+1,a+n+1);
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=i; j++) {
				for(int k=j; k<=i; k++) sum+= abs(a[i]-a[k]);
				if(sum<=m) {
					ans=max(ans,i-j+1);
					sum=0;
					break;
				}
				sum=0;
			}
		}
		cout<<ans;
	}

}
