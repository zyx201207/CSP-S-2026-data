#include <bits/stdc++.h>
using namespace std;
long long n,m;
vector<long long>cards(500005),c(500005),ans(500005);
map<long long,long long>ma;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i = 1;i<=n;i++){
		scanf("%lld",&cards[i]);
		ma[cards[i]]=0;
	}
	for(long long j = 1;j<=n;j++){
		for(long long i = j;i<=n;i++){
			if(ma[cards[i]]!=0){
				int kskbl = ma[cards[i]];
				for(long long cnt=i-1;kskbl<=cnt && cnt>0;cnt--){
					ma[cards[cnt]] = 0;
					c[cnt] = 0;
				}
			}
			c.push_back(cards[i]);
			ma[cards[i]]=i;
		}
		for(long long i = 1;i<=m;i++){
			if(ma[i]>0) ans[i]++;
			
		}
		ma.clear();
		c.clear();
	}
	for(long long i = 1;i<=m;i++){
		printf("%lld ",ans[i]);
	}
	return 0;
}
