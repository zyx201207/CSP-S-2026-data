#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,ans;
int a[N];
bool f;
vector<int> b[2];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[0].push_back(a[i]);
	}
	f=0;
	for(int i=30;i>=0;i--){
		for(auto j:b[f]){
			if(j&(1ll<<i)){
				b[!f].push_back(j);
			}
		}
		if(b[!f].size()<m){
			b[!f]=b[f];
		}else{
			ans+=(1<<i);
		}
		b[f].clear();
		f=!f;
	}
	cout<<ans<<"\n";
	return 0;
}
