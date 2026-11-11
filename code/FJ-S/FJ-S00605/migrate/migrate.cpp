#include<bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000002],dp[2000002],ans;
deque<int>q;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int i=1;i<=n;i++){
			q.clear();
			q.push_back(i),dp[i]=0;
			for(int j=i+1;j<=n;j++){
				while(q.size()&&x[j]-x[q.front()]>d)q.pop_front();
				if(q.empty())break;
				if(q.size()>1){
					int tmp=q.front();q.pop_front();
					if(q.size()>1){
						int lmx=q.front();q.pop_front();
						if(dp[tmp]==dp[lmx]&&dp[lmx]!=dp[q.front()])ans++;
						q.push_front(lmx);
					}else if(dp[tmp]==dp[q.front()])ans++;
					q.push_front(tmp);
				}
				dp[j]=dp[q.front()]+1;
				while(q.size()&&dp[q.back()]>dp[j])q.pop_back();
				q.push_back(j);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
