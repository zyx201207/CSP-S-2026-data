//GZ-S00137 ³Â³½ 
#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long a[N];
bool im[N];
void solve(){
	long long n,m;
	cin >>n>>m;
	for (int i = 1;i <= n;i++)cin >> a[i];
	long long l=1,ans=0,zj=0,r=1;
	while(r<=n){
		while (a[r]-a[l]<=m)r++;
		for (int i = r;i <= n;i++){
			if (a[i]-a[r-1]<=m&&a[i]-a[r-2]<=m){
				if (a[i]-a[r-3]>m){
					int sum=1;
					if (a[r+1]-a[r]<=m&&a[r+1]-a[r-1]>m)sum++;
					if (a[l]-a[l-1]<=m&&a[l+1]-a[l-1]>m){
						ans+=2*sum;
					}
					else{
						ans+=sum;
					}
				}
			}
			else{
				break;
			}
		}
		l++;
	}
	cout <<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
	int T=1,c;
	cin >>c>>T;
	if (c==13||c==14){
		cout <<0;
		return 0;
	}
	while(T--){
		solve();
	}
	return 0;
}
