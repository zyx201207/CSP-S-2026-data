#include<bits/stdc++.h>
#define int long long 
#define LOCAL 0
#define ONLINE 1
using namespace std;
const int N=1e6+10;
int a[N],n,m,cnt,ans;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	#if LOCAL 
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	#if ONLINE 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1,j=1;i<=n;i++){
		cnt+=(a[i]-a[i-1])*(i-j);
	//	cout<<a[i]<<' '<<j<<' '<<i<<' '<<cnt<<'\n';
		while(j<i&&cnt>m)cnt-=a[i]-a[j],j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
}
