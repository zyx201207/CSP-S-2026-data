#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
const int N = 1e5+5;
int t,c,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> k;
		cout <<n-k << '\n';
	}
	return 0;
}
