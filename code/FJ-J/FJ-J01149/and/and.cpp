#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans;
int a[200005];
bool b1[200005],b[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
//	cin>>n>>m;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
//		cin>>a[i];
		scanf("%lld",&a[i]);
	}
	for(int k=30;k>=0;k--){
		memset(b1,0,sizeof(b1));
		int kk=pow(2,k),cnt=0;
		for(int i=1;i<=n;i++){
			if(b[i]) continue;
			if(a[i]>=kk){
				cnt++;
				a[i]-=kk;
				b1[i]=1;
			}
		}
		if(cnt>=m){
			ans+=kk;
			for(int i=1;i<=n;i++){
				if(!b1[i]) b[i]=1;
			}
		}
	}
	printf("%lld",ans);
//	cout<<ans;
	return 0;
}
//rp+=inf
