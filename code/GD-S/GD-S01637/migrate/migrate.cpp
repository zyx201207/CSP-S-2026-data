#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n;
		long long d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(d==1){
			cout<<0<<endl;
			continue;
		}
		long long c=a[2]-a[1];
		long long ans=0;
		long long zc=d/c;
		for(int i=n-zc-1;i>=1;i--){
			ans+=i;
		}
		for(int i=zc+2;i<=n;i++){
			if((a[i]-a[1])%d!=d-1&&(a[i]-a[1])%c!=d-1){
				ans--;
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
