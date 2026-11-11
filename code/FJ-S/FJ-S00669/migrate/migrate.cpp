#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t;
ll x[2000000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		ll n,d,cnt=0;
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		if(n==1){
			cout<<0<<"\n";
			break;
		}
		for(int k=1;k<=n-3;k++){
			bool kk=1;
			for(int l=k+1;l<=k+3;l++){
				if(kk==0)break;
				if(x[l]-x[l-1]>d){
					kk=0;
				}
			}
			if(kk==1){
			cnt++;
			//cout<<k<<" "<<k+3<<"\n";	
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
