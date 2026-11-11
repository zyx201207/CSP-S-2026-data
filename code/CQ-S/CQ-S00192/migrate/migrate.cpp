#include<bits/stdc++.h>
#define ll long long
using namespace std;
int CCC;
int n;
ll d;
ll x[2000010];
int dis[310];
int g[310];
void solve(){
	cin>>n>>d;
	bool ok=1;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	for(int i=3;i<=n;i++){
		if(x[i]-x[i-1]!=x[i-1]-x[i-2]){
			ok=0;
			break;
		}
	}
	if(ok){
		if(n==1){
			cout<<0<<"\n";
		}
		else{
			ll k=min(d/(x[2]-x[1]),1LL*n-1);
			if(k<=1){
				cout<<0<<"\n";
			}
			else{
				ll res=0;
				for(int i=1;i<=n;i++){
					int tmp=i-2*k+1;
					if(tmp>=1)res++;
				}
				cout<<res<<"\n";
			}
		}
		return;
	}
	if(n<=300){
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[j]=0x3f3f3f3f;
				g[j]=0;
			}
			dis[i]=0;
			g[i]=1;
			queue<int>q;
			q.push(i);
			while(q.size()){
				int u=q.front();
				q.pop();
				for(int j=1;j<=n;j++){
					if(abs(x[u]-x[j])<=d){
						if(dis[j]>dis[u]+1){
							dis[j]=dis[u]+1;
							q.push(j);
							g[j]=g[u];
						}
						else if(dis[j]==dis[u]+1){
							g[j]+=g[u];
							g[j]=min(g[j],3);
						}
					}
				}
			}
			for(int j=1;j<=n;j++){
				if(g[j]==2){
					res++;
				}
			}
		}
		cout<<res/2<<"\n";
		return;
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,tt;
	cin>>c>>tt;
	CCC=c;
	while(tt--)solve();
	return 0;
}
