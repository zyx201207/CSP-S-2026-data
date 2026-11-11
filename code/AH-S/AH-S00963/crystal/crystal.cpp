#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,M=1e5+5;
unordered_map<string,bool> mp;
ll a[N],ans=0;
int n;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ll m;
	int ans=0;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	int l=1,r=2;
	while(r<=n){
		m-=(r-l)*(a[r]-a[r-1]);
		while(m<0&&l<r){
			m+=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1);
		r++;
	}
	printf("%d",ans);
	return 0;
}
