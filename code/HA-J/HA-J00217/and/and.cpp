#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
const int N=2e5+5;
int n,m;
ll a[N];
vector <int> c[34];
int f[N];
void solve(){
	cin >> n >> m;
	for(int i=1;i<=n;++i){
		cin >> a[i];
	}
	
	for(int i=1;i<=n;++i){
		for(int k=0;;++k){
			if((1<<k)>a[i]){
				//cout << k << " " << a[i] << " " << (a[i]>>(k-1)) << '\n';
				break;
			}
			if((a[i]>>k)&1){
				c[k].emplace_back(i);
				//cout << " " << k << " " << (1<<k) << " "  << a[i] << '\n';
			}
		}
	}
	ll res=0,ans=0;
	for(int i=31;i>=0;i--){
		if(c[i].size()>=m){
			int cnt=0;
			for(int j=0;j<c[i].size();++j){
				if(f[c[i][j]]==res){
					cnt++;
				}
			}
			if(cnt>=m){
				for(int j=0;j<c[i].size();++j){
					if(f[c[i][j]]==res){
						f[c[i][j]]++;
					}
				}
				res++;
				ans+=1ll*(1<<i);
				//cout << ans << " " << i << '\n';
			}	
			//cout << i << "aaa\n";
		}
	}
	cout << ans;	
	return ;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int _T=1;//cin >> _T;
	while(_T--){
		solve();
	}
	return 0;
}
