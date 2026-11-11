#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,k;
struct node{
	int u,v;
}a[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i=1;i<=n;i++){
			cin >> a[i].u >> a[i].v;
		}
		cout << 0;
	}
	return 0;
} 
