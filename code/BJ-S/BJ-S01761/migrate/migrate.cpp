#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t,n,d,a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(abs(i-j)==d+1)ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

