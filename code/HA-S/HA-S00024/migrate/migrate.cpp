#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,string> pi;
ll c,t,n,d,a[5005],x,y,ans;
string s[1200005],s1="1";
vector<int> g[5005];
int mp[5005][5005];
void bfs(int st){
	queue<pi> q;
	q.push({st,s1});
	while(!q.empty()){
		pi now=q.front();
		q.pop();
		int u=now.first;
		string s2=now.second;
		y=0;
		for(auto v:g[u]){
			q.push({v,s2+char('0'+v)});
			y=1;
		}
		if(y==0) s[++x]=s2;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(mp,0,sizeof mp);
		cin>>n>>d>>a[1],x=0,ans=0;
		for(int i=2;i<=n;i++){
			cin>>a[i];
			for(int j=1;j<i;j++)
				if(a[i]-a[j]<=d){
					g[j].push_back(i);
				}
		}
		bfs(1);
		for(int i=1;i<=x;i++){
			int l=s[i].size(),y=s[i][l-1];
			mp[l][y]++;
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(mp[i][j]==2) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
