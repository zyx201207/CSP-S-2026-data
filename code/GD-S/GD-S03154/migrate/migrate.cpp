#include<bits/stdc++.h>
#define int long long
using namespace std;

int C,T,n,d,a[2000005],l,r;

int solve(){
	int id=l,can=1;
	vector<int> v;
	v.push_back(l);
	for(int i=l;i<r;++i){
		if(a[i+1]-a[id] > d){
			if(a[i]-a[id] > d){
				can=0;
				break;
			}
			v.push_back(i);
			id=i;
		}
	}
	if(a[r]-a[id] > d) can=0;
	v.push_back(r);
	int path=1;
	//for(auto x:v) cout<<x<<endl;
	for(int i=1;i<=v.size()-2;++i){
		if(v[i] < 3) continue;
		if(v[i]-1 == v[i-1]) continue;
		if(a[v[i+1]] - a[v[i]-1] <= d and a[v[i+1]]-a[v[i]-2] > d) path++;
	}
	if(can){
		if(path == 2){
			return 1;
		}else{
			return 0;
		}
	}else{
		return 0;
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&C,&T);
	while(T--){
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;++i){
			scanf("%lld",&a[i]);
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				l = i;
				r = j;
				ans += solve();
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
