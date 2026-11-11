#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int c,n,t,k;
long long d,ans;
long long x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12)
			int mx=d/(x[2]-x[1]);
			for(int i=mx+1;i<mx*2;i++){
				ans=ans+n-i;
			}
			cout<<ans<<endl;
			ans=0;
	}
	return 0;
}
