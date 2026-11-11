#include <bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long n,m,xx,ans,t,c,cnt=1;
vector <long long> a[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		ans=0;
		cnt=1;
		scanf("%lld",&n);
		scanf("%lld",&m);
		for(int i=1;i<=n;i++){
			scanf("%lld",&xx);
			if(a[cnt].empty())
				a[cnt].push_back(xx);
			else if(xx-a[cnt][a[cnt].size()-1]>m)
				a[++cnt].push_back(xx);
			else a[cnt].push_back(xx);
		}
		for(int k=1;k<=cnt;k++){
			cout<<a[k].size()<<endl;
			for(int i=1;i<=a[k].size()-3;i++){
				ans+=i;
			}
		}
		printf("%lld\n",ans);
	}
		
	return 0;
}
