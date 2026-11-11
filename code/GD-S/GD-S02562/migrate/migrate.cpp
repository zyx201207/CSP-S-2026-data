#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
const int INF=0x3f3f3f3f;
int a[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<=n-3;i++){
			if(a[i+3]-a[i]>m&&a[i+1]-a[i]<=m&&a[i+3]-a[i+1]<=m&&a[i+2]-a[i]<=m&&a[i+3]-a[i+2]<=m){
				int l=1,r=1;
				for(int j=i+4;j<=n;j++){
					if(a[j]-a[j-1]>m){
						break;
					}
					if(j>=4&&a[j]-a[j-3]>m&&a[j]-a[j-2]<=m&&a[j-2]-a[j-3]<=m&&a[j]-a[j-1]<=m&&a[j-1]-a[j-3]<=m){
						break;
					}
					r++;
				}
				for(int j=i-1;j>=1;j--){
					if(a[j+1]-a[j]>m){
						break;
					}
					if(a[j+3]-a[j]>m&&a[j+3]-a[j+2]<=m&&a[j+2]-a[j]<=m&&a[j+3]-a[j+1]<=m&&a[j+1]-a[j]<=m){
						break;
					}
					l++;
				}
				ans+=l*r;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

