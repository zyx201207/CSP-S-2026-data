#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,a[N],ans;//8914642299978 621311336
void solve1(){
	ll j,c;
	cin>>n>>m;
	 
	for(int i=1;i<=n;i++)
		cin>>a[i];
	c=a[2]-a[1];
//	cout<<"C:"<<c<<"\n";
//	cout<<"M:"<<m<<"\n";
	j=m/c;
//	cout<<"J:"<<j<<"\n";
	ans=(n-1)/j;
//	cout<<ans<<"\n";
	return;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c;
	if(c==11||c==12){
		int t;
		cin>>t;
		while(t--){
			solve1();
		}
	}
	return 0;
}
