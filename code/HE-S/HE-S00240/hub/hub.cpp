#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=2e6+5;
LL c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1,a,b;i<n;i++)cin>>a>>b;
		cout<<k-1<<'\n';
	}
	return 0;
}
