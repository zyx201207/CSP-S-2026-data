#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
ll a[N],d,r,n;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T,c;
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=2){
			cout<<0<<"\n";
			continue;
		}
		d=(d/(a[2]-a[1]));
		if(d<=1) cout<<0<<"\n";
		else cout<<max(0ll,n-(2*d-1))<<"\n";
	}
	return 0;
}
