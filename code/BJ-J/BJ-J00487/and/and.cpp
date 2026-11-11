#include<bits/stdc++.h>
using namespace std;
#define int long long
int num[200010];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==(n-1)){
		int ans=1048575,minn=2100000000;
		for(int i=1;i<=n;i++){
			scanf("%lld",&num[i]);
			minn=min(minn,num[i]);
		}for(int i=1;i<=n;i++){
			if(num[i]!=minn)ans&=num[i];
		}
		return 0;
	}
	if(m==n){
		int ans=1048575;
		for(int i=1;i<=n;i++){
			int a;scanf("%lld",&a);ans&=a;
		}cout<<ans;
		return 0;
	}
	int maxx=-1;
	for(int i=1;i<=n;i++){
		int a;scanf("%lld",&a);
		maxx=max(maxx,a);
	}cout<<maxx;
	return 0;
}
