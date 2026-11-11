#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,ans,w[1000005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=n;i<=n+3;i++){
		ans+=w[i];
	}
	cout<<c+n+m+d+q+3<<endl<<ans;
	return 0;
} 

