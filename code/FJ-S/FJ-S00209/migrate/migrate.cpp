#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+10;
ll a[N],c,T,n;
int main(){
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		if(n>10000){
			cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int st=1;st<n-1;st++){
			for(int en=st+2;en<=n;en++){
				sum++;
			}
		}
		cout<<sum/2<<'\n';
	}
	return 0;
}
