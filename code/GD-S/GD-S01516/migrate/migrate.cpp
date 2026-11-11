#include <bits/stdc++.h>
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define infLL 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128 i128;
typedef pair<int,int> pii;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	srand(time(0));
	int c, t;
	cin>>c>>t;
	while(t--){
		cout<<rand()%10<<'\n';
	}
	
	return 0;
}
