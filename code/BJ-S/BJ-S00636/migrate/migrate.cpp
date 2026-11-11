#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,d,x,D=LONG_LONG_MAX;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	int c,t;
	cin>>c>>t;
	if(1||c==11||c==12)
		while(t--){
			x=LONG_LONG_MAX;
			D=LONG_LONG_MAX;
			cin>>n>>d;
			while(n--){
				int cur;
				cin>>cur;
				if(D==LONG_LONG_MAX&&x!=LONG_LONG_MAX) D=cur-x;
				x=cur;
			}
			cout<<n-d/D*2+1<<endl;
		}
	return 0;
}
