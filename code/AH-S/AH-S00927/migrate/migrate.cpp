#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,n,a[N],ans;
unsigned long long d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;(i+d)<=a[n]&&i<=n;i++){
			for(int j=i;j<=i+5&&j<=n;j++){
				if(a[j]==a[i]+2*d-1){
					ans++;
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}

