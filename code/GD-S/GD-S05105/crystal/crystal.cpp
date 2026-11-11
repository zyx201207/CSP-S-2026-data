#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+3;

int n,m,ans;
int a[maxn],s[maxn];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;++i)s[i]=a[i+1]-a[i];
	for(int i=1;i<=n;++i){
		m-=s[i]*i;
		ans++;
		if(m<0)break;
	}
	cout<<ans;
	
	return 0; 
}
