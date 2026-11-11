#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=5e5+10;
ll n,m,a[maxn];
int ans=0,j=1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		m-=(i-j+1)*(a[i+1]-a[i]);
		while(j<=i&&m<0){
			m+=a[i+1]-a[j++];
		}
		ans=max(ans,i-j+2);
	}
	cout<<ans;
}
