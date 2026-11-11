#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+9;
int n,m;
int a[N];
vector<int>v[N];
int T[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=30;j>=0;j--){
			if(a[i]&(1<<j)){
				T[j]++;
				v[j].push_back(a[i]);
			}
		}
	}
	int ans=0;
	for(int i=30;i>=0;i--){
		if(v[i].size()<m)continue;
//		for(auto j:v[i]){
//			cout<<j<<'\n';
//		}
		ans+=(1<<i);
		for(int j=0;j<i;j++){
			v[j].clear();
		}
		for(auto j:v[i]){
			for(int k=i-1;k>=0;k--){
				if(j&(1<<k)){
					v[k].push_back(j);
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
