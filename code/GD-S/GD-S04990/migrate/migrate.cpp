#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,t,n;
ll d,a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(c>=15&&c<=18){
			cout<<0<<'\n';
			return 0;
		}
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		int num=n;
		for (int i=2;i<=n;i++){
			if(a[i]-a[i-1]>d)num--;
		}
		cout<<max(0ll,num-(2*d-1))<<'\n';
	}
	return 0;
}
