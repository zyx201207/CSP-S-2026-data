#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
int n,d,cnt;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>t;
	cin>>n>>d;
	while(t--){
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if((x[j]-x[i])%d==0) cnt++;
			}
		}
		cout<<cnt<<"/n";
	}
	return 0;
}
