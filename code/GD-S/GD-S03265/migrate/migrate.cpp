#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x,y,ans,a[2000010],dp[2000010];
deque<int>p;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int l=1;l<n;l++){
			while(!p.empty()) p.pop_back();
			dp[l]=0;
			p.push_back(l);
			for(int i=l+1;i<=n;i++){
				while(!p.empty()&&a[i]-a[p.front()]>d) p.pop_front();
				if(!p.empty()) dp[i]=dp[p.front()]+1;
				else break;
				while(!p.empty()&&dp[p.back()]>dp[i]) p.pop_back();
				if(p.size()>1){
					x=p.front();
					p.pop_front();
					y=p.front();
					p.pop_front();
					if(dp[x]==dp[y]&&(p.empty()||dp[p.front()]==dp[i])) ans+=1;
					p.push_front(y);
					p.push_front(x);
				}
				p.push_back(i);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
