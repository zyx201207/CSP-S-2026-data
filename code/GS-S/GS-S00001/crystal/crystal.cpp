#include<bits/stdc++.h>
using namespace std;
#define int long long
#define inl inline
#define re register
#define itn int
const int N=5e5+10;
int n,m,a[N],b[N],ans,len;
signed main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("r","crystal.in",stdin);
	freopen("w","crystal.out",stdout);
	cin>>n>>m;
	for(re int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(re int i=1;i<n;i++){
		len+=abs((a[i+1]-a[i])*i);
	}
	if(m<a[2]-a[1]){
		cout<<0;
		return 0;
	}
	if(m==(a[2]-a[1])){
		cout<<2;
		return 0;
	}
	if(m>=len){
		cout<<n;
		return 0;
	}
	for(re int i=1;i<n&&m>=0;i++){
		m-=((a[i+1]-a[i])*i);
		ans++;
	}
	cout<<ans;
	return 0;
}
