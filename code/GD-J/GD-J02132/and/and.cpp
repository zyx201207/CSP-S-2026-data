#include<bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for(int i=(int)(a);i<=(int)(b);i++)
#define int long long
const int N=2e5+10;
int n,m,ans,maxx,cnt[40];
pair<int,int> a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	REP(i,1,n){
		cin>>a[i].second;maxx=max(maxx,a[i].second);
		REP(j,0,30){
			if(!(a[i].second&(1<<j))) a[i].first+=(1<<j);
			else cnt[j]++;
		}
	}
	if(m==1) return cout<<maxx,0;
	REP(i,1,n) REP(j,0,30) if(a[i].second&(1<<j)&&cnt[j]==1) a[i].first+=(1<<j);
	sort(a+1,a+n+1);
	ans=a[1].second;
//	cout<<ans<<" "<<a[2].second<<"\n";
	REP(i,2,m) ans&=a[i].second;
	cout<<ans;
	return 0;
}
//Trick||Treat!
