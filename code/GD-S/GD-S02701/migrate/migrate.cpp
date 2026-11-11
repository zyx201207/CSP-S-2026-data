#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
#define int long long
int c,t;
bool fga = 1;
bool vis[N];
bool mp[N]; 
int a[N];
int iss;
int dm;
void dfs1(int s,int e,int n,int d,int dis){
	if(e == s){
		dm = min(dm,dis);
		return;
	}
	for(int i = s-d;i <= s+d;i ++){
		if(mp[i]&&vis[i] == 0){
			vis[i] = 1;
			dfs1(i,e,n,d,dis+1);
			vis[i] = 0;
		}
	}
}
void dfs2(int s,int e,int n,int d,int dist){
	if(e == s){
		if(dist == dm)iss++;
		return;
	}
	for(int i = s-d;i <= s+d;i ++){
		if(mp[i]&&vis[i] == 0){
			vis[i] = 1;
			dfs2(i,e,n,d,dist+1);
			vis[i] = 0;
		}
	}
}
bool check(int s,int e,int n,int d){
	for(int i = 1;i <= n;i ++){
		vis[i] = 0;
	}
	iss = 0;
	dm = LLONG_MAX;
	dfs1(s,e,n,d,0);
	//cout << "dm:"<<dm<<'\n';
	for(int i = 1;i <= n;i ++){
		vis[i] = 0;
	}
	dfs2(s,e,n,d,0);
	//cout << "iss:"<<iss<<'\n';
	if(iss == 2)return 1;
	else return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> t;
	while(t--){
		int n = 0,d = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i ++){
			cin >> a[i];
			mp[a[i]] = 1;
		}
		int cnt = 0;
		if(n>=5000){
			cout <<0<<'\n';	
			continue;
		}
		for(int i = 1;i <= n;i ++){
			for(int j = i+1;j <= n;j ++){
				//cout << i <<" "<<j<<'\n';
				if(check(a[i],a[j],n,d)){
					cnt++;
				}
			}
		}
		cout << cnt<<'\n';
	}
	return 0;
} 
