#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	int cur,dep;
};
ll x[2000010],c,t,d,n,num[2000010];
vector<int> cnt[2000010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		int ans=0;
		memset(x,0,sizeof(x));
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		for(int k=1;k<=n;k++){
			node a={k,0};
			memset(cnt,0,sizeof(cnt));
			queue<node> q;
			q.push(a);
			while(!q.empty()){
				node b=q.front();
				q.pop();
				int u=b.cur,w=b.dep;
				cnt[w].push_back(u);
				for(int i=u+1;i<=n;i++){
					if(x[i]-x[u]<=d)q.push({i,w+1});
					else break;
				}
			}
			for(int i=1;i<=n;i++){
				memset(num,0,sizeof(num));
				for(auto j:cnt[i]){
					if(x[j]-x[k]>d)num[j]++;
				}
				for(auto j:cnt[i]){
					if(num[j]==2)ans++;
				}
			}
		}
		cout<<ans/2<<'\n';
	}
	return 0;
}
