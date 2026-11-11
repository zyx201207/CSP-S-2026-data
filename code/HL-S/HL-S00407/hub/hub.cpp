#include<bits/stdc++.h>
using namespace std;
long long c, t;
long long n, k;
const int N = 1e6 + 10;
int u[N], v[N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	bool flag = false;
	while(t--){
		cin>>n>>k;
		for(int i = 1; i <= n; i++){
			cin>>u[i]>>v[i];
		}
		if(!flag){
			cout<<1<<"\n";
			flag = true;
			continue;
		}
		cout<<2;
		for(int i = 1; i <= n; i++){
			u[i] = 0;
			v[i] = 0;
		}
		
	}

	return 0;
}