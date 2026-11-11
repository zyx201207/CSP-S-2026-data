#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
const int N=2e6+10;
int n,d;
int a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int cha=a[2]-a[1];
		int mx=floor(d*1.0/cha);
		int cc=mx*2-1;
		cout<<max(0ll,n-cc)<<'\n';
	}
	return 0;	
}
