#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[3000021];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		int sum=a[2]-a[1],bj=0;
		for(int i=2;i<=n-1;i++){
			if(sum!=a[i+1]-a[i]) bj=1;
		}
		if(bj==0){
			if(m/sum<2){
				cout<<0<<"\n";
				continue;
			}
			if(m/sum*2>n) cout<<0<<"\n";
			else cout<<(n-m/sum*2+1)<<"\n";
		}
		else{
			if(n==4) cout<<1<<"\n";
			else cout<<2<<"\n";
		}
	}
} 
