#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,t;
int n,d;
ll x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		bool f=false;
		ll ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(d==1){
			cout<<0<<endl;
			continue;
		}
		ll num=0;
		for(int i=1;i<=n;i++){
			if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
				num++;
			}
		}
		if(num==2){
			cout<<1<<endl;
			continue;
		}
		cout<<n-3<<endl;
		for(int i=1;i<=n;i++){
			if(x[n]-x[i]==n-i+1&&n-i+1==2&&d==2){
				ans++;
			}
		}
	}
	return 0;
}
