#include<bits/stdc++.h>
#define int long long
using namespace std;
int bh,t,n,d,a[2000005],ans;
int s[2000005],dis[2000005];
void solve(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) 
			s[j]=0,dis[j]=0; s[i]=1;
		for(int j=i+1,x=i,y=1;j<=n;j++){
			if(a[j]>a[j-1]+d) break;
			if(a[j]>a[x]+d) x=j-1,y++;
			dis[j]=y;
		}
		for(int j=i+1;j<=n;j++){
			if(a[j]>a[j-1]+d) break;
			int x=lower_bound(a+1,a+1+n,a[j]-d)-a;
			int y=lower_bound(dis+1+i,dis+1+j,dis[j])-(dis+1);
			if(s[y]-s[x-1]==2) ans++;
			s[j]=s[j-1]+s[y]-s[x-1];
		}
	}cout<<ans<<'\n'; return;
}
void solve1(){
	if(2*(a[2]-a[1])>d){ cout<<"0\n"; return; }
	int x=d/(a[2]-a[1]);
	cout<<max(0ll,n+1-2*x)<<'\n';
	return;
}
void solve2(){
	for(int i=1;i<=n;i++){
		int j=lower_bound(a+1,a+1+n,a[i]-d)-a;
		s[j]++;
	}
	for(int i=1;i<=n;i++){
		int j=upper_bound(a+1,a+1+n,a[i]+d)-(a+1);
		if(j>i+1) ans+=s[j-1];
	}
	cout<<ans<<'\n'; return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>bh>>t;
	while(t--){
		cin>>n>>d; ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		if(n<=3){ cout<<"0\n"; continue; }
		if(bh<=10) solve();
		else if(bh<=12) solve1();
		else if(bh<=14) solve2();
		else solve();
	}
	return 0;
}
