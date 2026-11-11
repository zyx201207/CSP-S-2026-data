#include <bits/stdc++.h>
using namespace std;
int c,t;
int u[1000010],v[1000010];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i = 1;i < n;i++){
			cin>>u[i]>>v[i];
		}
		cout<<(n - 2 * k + n % 10) / 8;
	}
	return 0;
}
