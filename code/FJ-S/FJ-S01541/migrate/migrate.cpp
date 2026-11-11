#include<bits/stdc++.h>
#define int long long
const int N=1e6+5;
using namespace std;
int a[N];
int ans;
int n,d;
bool check(int st,int nd){
	int cnt=0;
	for(int i=st+1;i<=nd;i++){
		if(a[i]-a[i-1]>d) return false; 
	}
	for(int j=2;j<=4;j++){
		for(int i=st+j;i<=nd;i++){
			if(a[i]-a[i-j]<=d) cnt++;
		}
	}
	if(cnt==2) return true;
	return false;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%lld%lld",&c,&T);
	while(T--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(check(i,j)){
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

