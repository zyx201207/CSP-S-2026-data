#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e6+5;
int c,T,n,d,a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		bool flag=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=0;
		} 
		if(flag){
			int x=a[2]-a[1];
			int len=a[n]-a[1];
			if(x>=d) cout<<0<<'\n';
			else{
				int k=d/x;
				k=2*k-1;
				if(k*x>len) cout<<0<<'\n';
				else cout<<n-k<<'\n';
			}
		}else cout<<0<<'\n';
	}
	return 0;
} 
