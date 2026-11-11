#include<bits/stdc++.h>
using namespace std;
const int N=2e6+50,mod=1e9+7;
int n,m;
long long a[N];
int ans=0;
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	ans=0;
	sort(a+1,a+1+n);
	long long sum=0;
	for(int i=1,j=1;i<=n;i++){
		sum+=a[i];
		while(a[i]*(i-j+1)-sum>m&&j<=i){
			sum-=a[j];
			++j;
		}
		ans=max(ans,(i-j+1));
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	} 
	return 0;
} 
