#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],c,T;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(2*(a[2]-a[1])<=m)cout<<max(0,(int)(n-3))<<endl;
		else cout<<0<<endl;
	}
}
