#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+10;
const int inf=1e8;

int c,t;
int n,d,cnt;
int num[N];
int dp[N];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c>>t;
	while(t--){
		cnt=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>num[i];
		deque<int> q;
		for(int i=1;i<=n;i++) dp[i]=0;
		for(int i=1;i<=n;i++){
			while(!q.empty()&&abs(num[q.front()]-num[i])>d){
				q.pop_front();
			} 
			if(!q.empty()) dp[i]=dp[q.front()]+1;
			while(!q.empty()&&dp[q.back()]>dp[i]){
				q.pop_back();
			} 
			if(!q.empty()){
				int x=q.back();q.pop_back();
				if(dp[q.back()]!=dp[i]&&dp[x]==dp[i]) cnt++;
				q.push_back(x);
			} 
			q.push_back(i);
		}
		cout<<cnt<<endl;
	}
	
	return 0;
}

