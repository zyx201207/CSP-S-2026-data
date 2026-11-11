#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int c,T,n,d;
int a[N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n<=3){
			cout<<0<<"\n";
			continue;
		}
		if(c==0||c==11||c==12){
			int x=a[2]-a[1];
			if(d<x*2ll){
				cout<<0<<"\n";
			}
			else 
			cout<<max(0ll,n-2*(d/x)+1)<<"\n";
		}
	}
	return 0;
}
