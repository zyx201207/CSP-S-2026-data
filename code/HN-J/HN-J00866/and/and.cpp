#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	for(long long i=1;i<=n;i++){
		ans=max(ans,a[i]);
	}
	cout<<ans<<'\n';
	return 0;
}
