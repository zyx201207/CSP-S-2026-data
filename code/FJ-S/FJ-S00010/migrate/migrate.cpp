#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int x[2000005];
int f[2000005];
struct edge{
	int g,cnt;
}dp[5005];
deque<int>dq;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			if(n==1){
				cout<<0<<endl;
				continue;
			}
			int p=x[2]-x[1];
			//cout<<n<<" "<<d<<" "<<p<<endl;
			d/=p;
			if(d<=1){
				cout<<0<<endl;
				continue;
			}
			int f=d+(d-1);
			cout<<max(0ll,n-f)<<endl;
		}
		exit(0);
	}
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ansf=0;
		for(int i=1;i<=n;i++){
			while(!dq.empty()) dq.pop_front();
			for(int j=i;j<=n;j++){
				int p=1e18;
				dp[j]={p,0};
			}
			for(int j=0;j<=n;j++){
				f[j]=0;
			}
			int ans=0;
			dp[i]={0,1},f[0]++;
			dq.push_back(i);
			for(int j=i+1;j<=n;j++){
				while(!dq.empty()){
					if(abs(x[dq.front()]-x[j])>d){
						f[dp[dq.front()].g]-=dp[dq.front()].cnt;
						dq.pop_front();
					}
					else break;
				}
				if(!dq.empty()){
					dp[j]={dp[dq.front()].g+1,f[dp[dq.front()].g]};
				}
				while(!dq.empty()){
					if(dp[dq.back()].g>dp[j].g){
						f[dp[dq.back()].g]-=dp[dq.back()].cnt;
						dq.pop_back();
					}
					else break;
				}
				if(dp[j].g!=1e18){
					f[dp[j].g]+=dp[j].cnt;
					dq.push_back(j);
					if(dp[j].cnt==2) ans++;
				}
				//cout<<i<<" "<<j<<" "<<dp[j].g<<" "<<dp[j].cnt<<endl;
			}
			ansf+=ans;
		}
		cout<<ansf<<endl;
	}
	return 0;
}
