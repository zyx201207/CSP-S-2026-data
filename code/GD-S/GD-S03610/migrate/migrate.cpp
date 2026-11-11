#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		long long n,d;
		cin>>n>>d;
		vector<long long>a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			queue<pair<long long,long long>>q;
			map<pair<long long,long long>,long long>cnt;
			q.push({i,0});
			while(!q.empty()){
				int now=q.front().first,dis=q.front().second;
				q.pop();
				cnt[{now,dis}]++;
				int x=now;
				while(x++&&x<=n){
					if(a[x]-a[now]<=d) q.push({x,dis+1});
					else break;
				}
			}
			for(int j=i+1;j<=n;j++){
				for(int q=2;q<=n;q++){
					if(cnt[{j,q}]==2) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
