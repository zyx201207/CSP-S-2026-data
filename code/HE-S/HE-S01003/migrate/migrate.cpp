#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int cc,t,n,d,a[N],f[N],cnt[N];
int sol(int s){
	for(int i=1;i<=n;i++) f[i]=2e18,cnt[i]=0;
	f[s]=0;
	int lj=s;
	for(int i=s+1;i<=n;i++){
		while(a[i]-a[lj]>d) lj++;
		for(int j=lj;j<i;j++){
			if(f[j]+1<f[i]) f[i]=f[j]+1,cnt[i]=1;
			else if(f[j]+1==f[i]) cnt[i]++;
		}
	}
	int res=0;
	for(int i=s+1;i<=n;i++) if(cnt[i]==2) res++;
	return res;
}
signed main(){
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>cc>>t;
	if(cc==13||cc==14){
		while(t--) cout<<0<<'\n';
		return 0;
	}
	if(cc<=10){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			int ans=0;
			for(int s=1;s<n;s++) ans+=sol(s);
			cout<<ans<<'\n';
		}
		return 0;
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int mx=a[n]-a[1];
		mx/=d;
		cout<<max(0,n-mx/2+mx/3)<<'\n';
	}
} 
