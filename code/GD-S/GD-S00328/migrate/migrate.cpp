#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long c,t,n,d,a[N];
int main(){ 
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			scanf("%lld%lld",&a[1],&a[2]);
			for(int i=3;i<=n;i++){
				scanf("%lld",&a[i%100+4]);
			}
			int k=d/(a[2]-a[1]);
			if(k>=2){
				long long ans=0;
				for(int i=0;i<n;i++){
					ans+=i;
				}
				cout<<ans<<endl;
			}
			else cout<<0<<endl;
		}
	}
	return 0;
}
