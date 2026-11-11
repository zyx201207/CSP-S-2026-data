#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
#define i128 __int128
using namespace std;
const int N=1e6+10;
int n,m,a[N];
i128 pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
//		pre[i]=pre[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	int ans=1;
	i128 ch=m;
	for(int i=2;i<=n;i++){
		i128 l=1,r=i,cnt=0;
		while(l<=r){
			i128 mid=(l+r)/2;
			i128 x=pre[i]-pre[i-mid];
			if((mid*a[i]-x)<=ch){
				cnt=mid;
				l=mid+1;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,(int)cnt);
	}
	cout<<ans;
	return 0;
}

