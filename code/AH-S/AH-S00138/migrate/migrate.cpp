#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,t,n,d,a[2000005];
bool _4=true;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		_4=true;
		for(int i=1;i<=n;i++) cin>>a[i];
		ll x=a[2]-a[1];
		for(int i=3;i<=n;i++) _4=_4&&a[i]-a[i-1]==x;
		if(c==11||c==12||_4){
			ll s=0;
			for(int i=2;i<=n;i++){
				if(abs(a[i]-a[1])>d) break;
				s++;
			}
			if(s>=2) cout<<max(0ll,n-3-(s-2)*2);
			else cout<<0;
		} else if(c<=6){
			vector<ll> g[305];
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(abs(a[i]-a[j])<=d){
						g[i].push_back(j);
						g[j].push_back(i);
					}
				}
			}
			ll s=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					ll mn=0;;
					char b[305]={};
					queue<ll> q,q1;
					q.push(i);
					q1.push(0);
					while(!q.empty()){
						ll p=q.front(),s=q1.front();
						q.pop();
						q1.pop();
						if(p==j){
							mn=s;
							break;
						}
						for(auto &v:g[p]){
							if(!b[v]){
								b[v]=1;
								q.push(v);
								q1.push(s+1);
							}
						}
					}
					ll c=0;
					queue<ll> q2,q3;
					q2.push(i);
					q3.push(0);
					while(!q2.empty()){
						ll p=q2.front(),s=q3.front();
						q2.pop();
						q3.pop();
						if(p==j&&s==mn){
							c++;
							if(c>2) break;
							continue;
						}
						if(s==mn) continue;
						for(auto &v:g[p]){
							q2.push(v);
							q3.push(s+1);
						}
					}
					if(c==2) s++;
				}
			}
			cout<<s;
		}
		cout<<'\n';
	}
	return 0;
}
