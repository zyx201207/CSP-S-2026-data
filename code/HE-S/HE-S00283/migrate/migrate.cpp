#include <iostream>
#define MAXN 2000009
using namespace std;
long long pos[MAXN],d,q;
int c,n,t,ans,num;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		bool b=true;
		cin >> n >> d;
		int i;
		for(i=1;i<=n;i++){
			cin >> pos[i];
			if(b&&i>1){
				q=pos[i]-pos[i-1];
				b=false;
			}
		}
		num=d/q;
		if(num<=1) cout << 0 << '\n';
		for(int i=1;i<n;i++){
			if(i+num+num-1>n){
				cout << i-1 << '\n';
                break;
			}
		}
	}
	return 0;
}
