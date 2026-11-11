#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,k,a[200001][200001];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		cout<<max(n-k,k-n);
	}
	return 0;
}
