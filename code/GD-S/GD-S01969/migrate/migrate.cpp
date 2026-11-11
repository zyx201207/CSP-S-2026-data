#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long n,d;
long long x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		memset(x,0x00,sizeof(x));
		cin>>n>>d;
		long long ans=0;
		int pre=0;
		long long db=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			if(i>=4){
				if(x[i]-x[i-2]<=d&&x[i-1]-x[i-3]<=d&&x[i]-x[i-3]>d){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
