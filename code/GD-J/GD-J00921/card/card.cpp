#include<bits/stdc++.h>
using namespace std;
//#define JUDGE
#define int long long
int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while(ch < '0'||ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9')x = (x << 3) + (x << 1) + (ch - '0'),ch = getchar();
	return x * f;
}
const int N = 1e6 + 10;
int n,m;
int a[N];
void input(){
	cin >> n >> m;
	for(int i = 1;i<=n;i++)cin >> a[i];
}
vector<int>desk;
int vis[N];int pos[N];
int ans[N];
void solve(){
	input();
	for(int i = 1;i<=n;i++){
		desk.clear();
		for(int j = 1;j<=n;j++)vis[i] = 0,pos[i] = 0;
		for(int j = i;j<=n;j++){
			if(a[j] == 2)cout << "cc\n";
			if(vis[a[j]] == 0){
				vis[a[j]] = 1,desk.push_back(a[j]);
				pos[a[j]] = desk.size() - 1;
				if(vis[2] == 1)cout << "c\n";
			} else {
				for(int k = pos[j];k<desk.size();k++)vis[desk[k]] = 0;
				for(int k = pos[j];k<desk.size();k++)desk.pop_back();
				desk.push_back(a[j]),vis[a[j]] = 1;
				if(vis[2] == 1)cout << "s\n";
			}
		}
		for(int j = 1;j<=n;j++)ans[j] += vis[j];
		cout << vis[2] << endl;
	}
	for(int i = 1;i<=m;i++)cout << ans[i] << " ";
}
signed main( ){
#ifndef JUDGE
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
#endif
	int _ = 1;
	//cin >> _;
	while(_--)solve();
	return 0;
}
