#include<bits/stdc++.h>
namespace KH{
using namespace std;
#define int long long
void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	for(int i=29;i>=0;i--){
		int t=1LL<<i,tt=0;
		ans|=t;
		for(int j=1;j<=n;j++){
			if((a[j]&ans)==ans) tt++;
		}
		if(tt<m) ans^=t;
	}
	cout<<ans<<'\n';
}
void main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T=1;
	while(T--){
		solve();
	}
}
#undef int
}
int main(){KH::main();}
