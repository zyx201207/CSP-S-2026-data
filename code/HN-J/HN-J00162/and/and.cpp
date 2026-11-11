#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N = 2e5 + 5;
const ll M = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
struct node{
	int x,d;
};
int n,m,a[N],cnt[35],f[35],ans;
bool vis[N][35];
vector<node> g;
void work(){
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		for(int j = 0;j < 31;j++){
			if(a[i] & (1 << j)){
				vis[i][j] = 1;
				cnt[j]++;
			}
		}
	} 
	for(int i = 30;i >= 0;i--){
		if(cnt[i] >= m){
			g.push_back({i,cnt[i]});
		}
	}
	int len = g.size();
	int t = 0,num = 0;
	for(int i = 0;i < len;i++){
		int x = g[i].x,d = g[i].d;
		if(i == 0){
			t = d;
			f[x] = 1;
			num |= (1 << x);
			continue;
		}else{
			int tot = 0;
			for(int j = 1;j <= n;j++){
				if((a[j] & num) == num && vis[j][x] == 0){
					tot++;
				}
			}
			if(t - tot >= m){
				t -= tot;
				f[x] = 1;
				num |= (1 << x);
			}
		}
	}
	for(int i = 0;i < 31;i++){
		if(f[i]){
			ans |= (1 << i);
		}
	}
	cout << ans << "\n";
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int oT_To = 1;
	//cin >> oT_To;
	while(oT_To--){ work();}
	return 0;
}

