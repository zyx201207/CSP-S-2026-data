#include<bits/stdc++.h>
using namespace std;
int c,t,n;
const int N=2e6+5;
long long d,x[N];
vector<int>s;
bool vis[N];

map<pair<int,int>,int >mp;
map<pair<int,int>,int>cnt;
void dfs(int k){
	if(s.size()>1){
		for(int i=1;i<s.size();i++){
			if(s[i]-s[i-1]>d)return;
		}
		pair<int,int>u={s[0],s.back()};
		if(mp[u]!=0){
			if(mp[u]==s.size()){
				cnt[u]++;
			}else if(mp[u]>s.size()){
				mp[u]=s.size();
				cnt[u]=1;
			}
		}
		else mp[u]=s.size();
	}
	for(int i=(s.size())?s.back()+1:1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			s.push_back(i);
			dfs(k+1);
			s.pop_back();
			vis[i]=0;
		}
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;++j){
				mp[{i,j}]=0;
			}
		}
		dfs(0);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;++j){
				if(cnt[{i,j}]==2){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
