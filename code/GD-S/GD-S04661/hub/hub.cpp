#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const int kM = 2e6 + 10;

int C,T,n,k;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			int a,b;cin>>a>>b;
		}
		cout<<n/(k+1)<<'\n';
	}
	return 0;
}
