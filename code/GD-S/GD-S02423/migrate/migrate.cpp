#include<bits/stdc++.h> 
using namespace std;
#define int long long
int c;
int n,a[2000005],d[2000005];
void work(){
	cin>>n>>d[0];
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<n;i++) d[i]=a[i+1]-a[i];
	if(d[0]<2*d[1]) cout<<0;
	else {
		double cnt=d[0]/d[1];
		if(cnt>=n) cout<<0;
		else cout<<floor(n-cnt*2+1);
	}
	cout<<endl;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T;
	cin>>c>>T;
	while(T--){
		work();
	}
	return 0;
}
