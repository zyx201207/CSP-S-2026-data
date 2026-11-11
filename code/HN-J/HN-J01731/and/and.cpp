#include<bits/stdc++.h>
#define MAXN 200010
using namespace std;
typedef long long ll;
int n,m,a[MAXN];
bool d[MAXN];
inline bool check(int bit){
	int cnt=0;
	for(int i=1;i<=n;++i){
		if((a[i]>>bit&1)&&(!d[i])){
			++cnt;
		}
	}
	return cnt>=m;
}
inline void del(int bit){
	for(int i=1;i<=n;++i){
		if(!(a[i]>>bit&1)){
			d[i]=true;
		}
	}
}
int main(){
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
	} 
	ll ans=0;
	for(int i=30;i>=0;--i){
		if(check(i)){
			ans|=(1ll<<i);
			del(i);
		}
	}
	printf("%lld",ans);
	return 0;
}

