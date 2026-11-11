#include<bits/stdc++.h>
#define long long ll
using namespace std;
const int MAXN = 2e6+5;
int n,k;
int mp[MAXN][MAXN];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;cin >> c >> t;
	while(t--){
		cin >> n >> k;
		for(int i=1;i<=n;i++){
			int x,y;cin >>x >> y;
			mp[x][y]=mp[y][x] = 1;
		}
		
	}	
	return 0;

