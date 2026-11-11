#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
int c,T;
ll n,d;
ll x[2000005];
void sol1(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	ll c=x[2]-x[1];
	ll tmp=(d)/c;
	if(c>=d||n-tmp*2+1<=0){
		cout<<0<<endl;
		return ;
	} 
//	cout<<n<<' '<<d<<' '<<c<<endl; 
	cout<<n-tmp*2+1<<endl; 
}
vector<int> G[2000005];
int cnt=0;
void calc(int xx,int y,int cc,int nw,int cntt){
	if(cntt>cc)
		return ;
	if(nw==y){
//		cout<<cntt<<endl;
		cnt++;
		return ;
	}
	for(int i=nw+1;i<=y;i++){
		if(x[i]-x[nw]>d)
			break;
		calc(xx,y,cc,i,cntt+1);
	}
}
void sol2(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)
		G[i].clear();
	for(int i=1;i<=n;i++)
		cin>>x[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d){
//				G[j].pb(i);
				G[i].pb(j);
			}
		} 
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]<=d)
				continue; 
//			queue<pii> q;
//			q.push({i,0});
			int tmp=(x[j]-x[i]+1)/d;
			cnt=0;
			calc(i,j,tmp,i,0); 
////			cout<<i<<' '<<j<<endl;
//			while(!q.empty()){
//				int u=q.front().fi,nw=q.front().se;
////				cout<<u<<endl;
//				q.pop();
//				if(u==j&&nw==tmp){
//					cnt++;
//					if(cnt>2)
//						break;
//					continue;
//				}
//				if(nw>tmp)
//					break;
//				for(auto v:G[u])
//					q.push({v,nw+1});
//			} 
			if(cnt==2)
				ans++;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>c>>T;
	while(T--){
		if(c==11||c==12){
			sol1();
		}
		else
			sol2();
	} 
	return 0;
} 
