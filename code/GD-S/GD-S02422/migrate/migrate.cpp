#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,a[2000001],s[5001],p[5001],b[2000001];
vector<int> g[5001];
void solve1(){
	while(t--){
		int ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			g[i].clear();
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=d)g[j].push_back(i);
				else break;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)p[j]=s[j]=0;
			queue<int> q;
			q.push(i);
			p[i]=s[i]=1;
			while(q.size()){
				int u=q.front();
				q.pop();
				if(p[u]==2)ans++;
				for(int v:g[u]){
					if(!s[v]){
						s[v]=s[u]+1;
						q.push(v);
					}
					if(s[v]==s[u]+1)p[v]+=p[u];
				}
			}
		}
		cout<<ans<<"\n";
	}
}
void solve2(){
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int x=d/(a[2]-a[1]);
		if(x<=1)cout<<"0\n";
		else cout<<max(n-2*x+1,0ll)<<"\n";
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(1<=c&&c<=10)solve1();
	else if(c==11||c==12)solve2();
} 
