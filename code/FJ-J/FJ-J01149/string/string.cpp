#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005];
int cnt1=0,cnt2=0,ans=0;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
//	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&c[i]);
//		cin>>a[i]>>c[i];
	}
	cnt1=1;
	cnt2=n;
	while(cnt1<cnt2){
		int mn=min(a[cnt1],a[cnt2]);
		if(c[cnt1]!=c[cnt2]){
			ans+=mn;
		}
		a[cnt1]-=mn;
		a[cnt2]-=mn;
		if(a[cnt1]==0) cnt1++;
		if(a[cnt2]==0) cnt2--;
//		cout<<a[cnt1]<<" "<<a[cnt2]<<" "<<cnt1<<" "<<cnt2<<" "<<ans<<endl;
	}
	printf("%lld",ans);
//	cout<<ans;
	return 0;
}
//rp+=inf
