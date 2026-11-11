#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int a[2001000];
int ans=0;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				vector<int> t;
				queue<pair<int,int> > q;
				q.push({i,0});
				int ms=1e18;
				while(!q.empty()){
					pair<int,int> qq=q.front();
					q.pop();
					if(qq.first>j || qq.second>ms) continue;
					if(qq.first==j){
						t.push_back(qq.second);
						ms=min(ms,qq.second);
					}
					for(int k=qq.first;k<=j;k++){
						if(a[k]-a[qq.first]<=d) q.push({k,qq.second+1});
						else break;
					}
					
				}
				t.push_back(1e18);
				sort(t.begin(),t.end());
				if(t[0]==t[1]&& t[1]!=t[2]) ans++;
			}
		}
		cout<<ans;
	}
}
