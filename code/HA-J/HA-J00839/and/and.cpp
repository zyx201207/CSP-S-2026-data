#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
long long a[MAXN],ans=-1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	if (m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if (m==2){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				if (i!=j){
					ans=max(a[i]&a[j],ans);
				}
			}
		}
	}
	if (m==3){
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				for (int k=1;k<=n;k++){
					if(i!=k&&i!=j&&j!=k){
						ans=max(a[i]&a[j]&a[k],ans);
					}
				}
			}
		}
	}
	if (m==n&&n>3){
		for (int i=1;i<=n;i++) {
			ans=a[1];
			ans+=ans&a[i]; 
		}
	}
	cout<<ans;
	return 0;
}




