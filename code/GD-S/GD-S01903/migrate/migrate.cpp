#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=2e6+5;
int a[N],lef[N],rig[N],nex[N],las[N],s[N],t[N],sum[N];
void solve(){
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>a[i];
//	for(int i=1;i<n;i++)cout<<a[i+1]-a[i]<<" ";
//	cout<<endl;
	for(int i=1;i<=n;i++){
		lef[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
		rig[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
	}
	for(int i=1;i<=n;i++)if(lef[rig[i]]==i)nex[i]=rig[i],las[rig[i]]=i;
//	for(int i=1;i<=n;i++)cout<<i<<" "<<las[i]<<" "<<nex[i]<<" "<<lef[i]<<" "<<rig[i]<<endl;
	for(int i=1;i<=n;i++)s[rig[i]]++,t[lef[i]]++;
	for(int i=1;i<=n;i++)s[nex[i]]+=s[i];
	for(int i=n;i>=1;i--)t[las[i]]+=t[i];
	for(int i=1;i<=n;i++)s[i]++,t[i]++;
	for(int i=1;i<=n;i++)sum[lef[i]]++;
//	for(int i=1;i<=n;i++)cout<<i<<" "<<t[i]<<endl;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(rig[i]-i<=1)continue;
		if(rig[rig[i]]==rig[i])continue;
		ans+=sum[rig[i]-1];
		if(lef[rig[i]-1]==i)ans+=(s[i]-1)*sum[rig[i]-1];
		if(lef[rig[rig[i]]]==rig[i]-1)ans+=t[rig[rig[i]]]-1;
		if(lef[rig[rig[i]]]==rig[i]-1 && lef[rig[i]-1]==i)ans+=(s[i]-1)*(t[rig[rig[i]]]-1);
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)s[i]=t[i]=lef[i]=rig[i]=nex[i]=las[i]=sum[i]=0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0);cout.tie(0);
	ios::sync_with_stdio(false);
	int c,T;
	cin>>c>>T;
	while(T--)solve();
}
