#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N =1e5+10,inf = 0x3f3f3f3f;
int n,m,a[N],maxx = -inf,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(int mask = 0;mask <= (1<<(n+1));mask++){
		ll cnt = 0;
		vector<ll> v;
		for(int i = 1;i<=n;i++){
			if(mask>>i & 1){
				v.push_back(a[i]);
				cnt++;
			}
			if(cnt > m)break;
		}
		if(cnt != m) continue;
		int ans = v[0];
		for(int i = 1;i<int(v.size());i++){	
			ans = ans & v[i];
		}
		maxx = max(ans,maxx);
	}
	cout<<maxx;
	return 0;
}
