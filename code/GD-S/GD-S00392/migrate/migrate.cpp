#include<bits/stdc++.h>
using namespace std;

const int N=2e6+5,T=5005,mod1=1497032437,mod2=1403000441;
int c,t,n,to[N];
long long d,x[N],cnt[N],f[N];
pair<long long,long long>sum[N];
pair<int,pair<long long,long long> >dp[N];
queue<int>q;
inline void work(int pos){sum[pos]=make_pair((sum[pos].first%mod1+mod1)%mod1,(sum[pos].second%mod2+mod2)%mod2);}
inline void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;++i) cin>>x[i];
	if(n==1){
		cout<<"0\n";
		return;
	}
	bool flag=true,op=true;
	for(int i=2;i<=n;++i) flag&=(x[i]-x[i-1])==(x[2]-x[1]);
	if(flag){
		if(d/(x[2]-x[1])>1) cout<<max(0ll,n-(2*(d/(x[2]-x[1]))-1))<<"\n";
		else cout<<"0\n";
		return;
	}
	for(int i=1;i<=n;++i) op&=(x[i]-x[1]<=d)&&(x[n]-x[i]<=d);
	if(op){
		long long res=0;
		for(int i=1;i<=n;++i) cnt[i]=0;
		cnt[n+1]=0;
		for(int l=1,pos=1;l<=n;++l){
			while(pos<n&&x[pos+1]<=x[l]+d) ++pos;
			++cnt[pos];
		}
		for(int r=n,pos=n;r;--r){
			while(pos>1&&x[r]-d<=x[pos-1]) --pos;
			res+=cnt[pos+1];
		}
		cout<<res<<"\n";
		return;
	}
	x[0]=x[1]-d-1;
	int pos,ans=0;
	for(int l=1;l<=n;++l){
		dp[l]=make_pair(0,make_pair(1,1));
		sum[0]=make_pair(1,1);
		q.push(l),pos=n+1;
		for(int r=l+1;r<=n;++r){
			while(!q.empty()&&x[r]-x[q.front()]>d){
				sum[dp[q.front()].first].first-=dp[q.front()].second.first;
				sum[dp[q.front()].first].second-=dp[q.front()].second.second;
				work(dp[q.front()].first);
				q.pop();
			}
			if(q.empty()){
				pos=r;
				break;
			}
			dp[r]=make_pair(dp[q.front()].first+1,sum[dp[q.front()].first]);
			sum[dp[r].first].first+=dp[r].second.first;
			sum[dp[r].first].second+=dp[r].second.second;
			work(dp[r].first);
			q.push(r);
		}
		while(!q.empty()) sum[dp[q.front()].first]={0,0},q.pop();
		for(int i=l;i<pos;++i) ans+=(dp[i].second.first==2&&dp[i].second.second==2);
	}
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--) solve();
	return 0;
}
/*
0 4
10 9
1 3 4 5 9 13 14 15 16 17
11 900
135 486 502 556 576 684 714 1263 1356 1456 2466
10 9
1 3 4 5 9 13 14 15 16 17
10 900
135 486 502 556 576 684 714 1263 1356 1456
*/
