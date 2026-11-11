#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f3f3f3f3fLL;
const int N=2e5+5;
int n,a[N],L,ans;
char c[N];
char ch;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	for(int i=1;i<=(n+1)/2;i++){
		if(c[i]!=c[n+1-i]){
			ans+=min(a[i],a[n+1-i]);
			ans+=abs(a[i]-a[n+1-i]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
