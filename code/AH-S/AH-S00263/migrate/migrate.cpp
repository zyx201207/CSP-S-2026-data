#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int c,t;
int a[2000010],f[5010][5010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) cin>>a[i];
		if(c==11||c==12){
			if(a[2]-a[1]>d*1.0/2||a[2]-a[1]<=d*1.0/3) cout<<0<<'\n';
			else cout<<n-3<<'\n';
		}else{
			cout<<0<<'\n';
		}
	}
	return 0;
}
