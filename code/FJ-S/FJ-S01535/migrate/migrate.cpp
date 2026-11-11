#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000010],guan[2000010],need[2000010],good[2000010],tail[2000010],ban[2000010],bad[2000010],dui[2000010];
int pre[2000010],suf[2000010],cnt,cnt2;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d,ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			guan[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
			if(guan[i]<=i+1)continue;
			if(a[guan[i]+1]-a[guan[i]-1]<=d&&a[guan[i]+1]-a[guan[i]-2]>d){
				need[i]=1,good[++cnt]=i;
				tail[guan[i]+1]=1;
				dui[guan[i]+1]=i;
			}
			if(a[guan[i]+1]-a[guan[i]-2]<=d){
				ban[i]=1,bad[++cnt2]=i;
				tail[guan[i]+1]=1;
				dui[guan[i]+1]=i;
			}
		}
		suf[n+1]=n+1;
		for(int i=n;i>=1;i--){
			if(need[i]||bad[i])suf[i]=min(suf[i+1],guan[i]+1);
			else suf[i]=suf[i+1];
		}
		for(int i=1;i<=n;i++){
			if(tail[i])pre[i]=max(pre[i-1],dui[i]);
			else pre[i]=pre[i-1];
//			cout<<pre[i]<<' '<<suf[i]<<'\n';
		}
		for(int i=1;i<=cnt;i++){
			int l=good[i],r=guan[good[i]]+1;
//			cout<<l<<' '<<r<<'\n';
			ans+=max(suf[l+1]-r,0ll)*max(0ll,l-pre[r-1]);
		}
		cout<<ans<<'\n';
		for(int i=0;i<=n+1;i++){
			need[i]=0;tail[i]=0;
			ban[i]=0;dui[i]=0;
			pre[i]=0;suf[i]=0;
			cnt=cnt2=0;
		}
	}
	return 0;
}
/*
10 3
-1000000000000000000 -999999999999999997 -999999999999999994 -999999999999999993 -999999999999999992 -999999999999999991 -999999999999999990 -999999999999999989 -999999999999999986 -999999999999999983
*/
