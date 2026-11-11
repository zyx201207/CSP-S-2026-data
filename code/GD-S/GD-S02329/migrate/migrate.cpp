#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,q,n,m,a[5000010];
signed main(){
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	while(q--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		int cha=a[2]-a[1];
		int k;
		if(cha==1) k=m;
		k=cha/m ;
		int ans=n+1-k-k;
		if(ans<=0 or m<cha or k<0) cout<<0<<endl;
		else cout<<ans<<endl;
	}
}

