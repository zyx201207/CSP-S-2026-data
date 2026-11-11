#include <bits/stdc++.h>
using namespace std;
const int N=2e6+5;
#define int long long
int c,t,x[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,d,cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			if(x[i+1]-x[i]>d) continue;
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d&&x[j]-x[i]<2*d&&(x[j]-x[i])%2!=0){
					 cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

