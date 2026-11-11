#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7,B=35;
int n,m,ans;
int a[N],x[N],y[N];
vector<int> v[B];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int cnt=n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int t=a[i];
		for(int j=32;j>=0;j--){
			if((t>>j)&1) v[j].push_back(i);
		}
	}
	for(int i=32;i>=0;i--){
		if(v[i].size()<m) continue;
		ans+=(1<<i);
		vector<int> t=v[i];
		for(int j=0;j<=32;j++) v[j].clear();
		for(int k:t){
			for(int j=32;j>=0;j--){
				if((a[k]>>j)&1) v[j].push_back(k);
				
			}
		}
	}
	cout<<ans;
	return 0;
} 
