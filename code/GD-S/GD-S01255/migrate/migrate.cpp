#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000006;
int c,t;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	srand(time(0));
	while(t--){
		cout<<rand()<<"\n";
	}
	return 0;
} 
