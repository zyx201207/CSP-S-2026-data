#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int c,t;
ll x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		if(c==11||c==12){
			int sum=x[2]-x[1];
			if(2*sum>=d){
				cout<<n-3;
			}else{
				cout<<0;
			}
		}else{
			cout<<n-3;
		}
	}
	return 0;
}
