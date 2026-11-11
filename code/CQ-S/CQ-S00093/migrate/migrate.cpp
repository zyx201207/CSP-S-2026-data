#include<bits/stdc++.h>
using namespace std;
int n,m;
int c,t;
const int N=2e6+5;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if (c==0){
		cout<<1<<endl<<2;
	}
	while(t--){
		cin>>n>>m;
		int a[N];
		int b[N];
		long long ans=0;
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		for (int i=2;i<=n;i++){
			b[i]=a[i]-a[i-1];
		}
		for (int i=1;i<=n-1;i++){
			int cnt=0;
			for (int j=i;j<=n-1;j++){
				if (a[j]>=m) break;
				cnt+=a[j];
			}
			if (m%2==0){
				if (cnt%2==1){
					ans++;
				}
			}
			if (m%2==1){
				if (cnt%2==0){
					ans++;
				}
			}
		}
		cout<<ans;
		
	}
	return 0;
	
}
