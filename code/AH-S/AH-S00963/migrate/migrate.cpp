#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5,M=1e5+5;
ll a[N];
vector<int> vt;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n;
	ll d;
	ll sum,ans,csum;
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		sum=0,ans=0,csum=0;
		for(int i=1;i<=n;i++){
			vt.clear();
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					sum++;
					vt.push_back(a[j]);
					continue;		
				}
				if(sum==2) ans++;
				else if(sum>=2*d){
					csum=0;
					for(int i=0;i<vt.size();i++){
						if(a[i]+d>=sum){
							csum++;			
						}
					}
					if(csum==2) ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
