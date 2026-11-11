#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
int c,t;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(d%2)d--;
		int x=d*2-(a[2]-a[1]);
		int ans=n-x;
		cout<<ans<<endl;
	}
	
	return 0;
} 
