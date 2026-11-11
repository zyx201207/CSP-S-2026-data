#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
ll n,m;
ll a[1000005],ju[1000005],cnt[1000005];
queue<pair<int,int>> que;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=1;j<=n;j++){
				ju[j]=0x3f3f3f3f,cnt[j]=0;
			}
			que.push({i,0});
			while(!que.empty()){
				auto x=que.front();
				que.pop();
				if(x.second<ju[x.first]){
					ju[x.first]=x.second;
					cnt[x.first]=1; 
				}
				else if(x.second==ju[x.first]){
					cnt[x.first]++;
				}
				if(x.second>ju[x.first]||x.first==n){
					continue;
				}
				int s=upper_bound(a+1,a+n+1,a[x.first]+m)-a;
				s-=1;
				for(int i=x.first+1;i<=s;i++){
					que.push({i,x.second+1});
				}
			}
			for(int j=i+1;j<=n;j++){
				if(cnt[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
