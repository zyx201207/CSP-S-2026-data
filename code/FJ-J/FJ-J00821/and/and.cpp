#include <bits/stdc++.h>
#define int long long
#define max(a,b) (a>b? a:b)
#define min(a,b) (a<b? a:b)
using namespace std;

int n,m,a[200010],k,maxs,ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		maxs=max(maxs,a[i]);
	}
	stable_sort(a+1,a+1+n,greater<int>());
	for(int p=(1<<30),f=0;p>=1;p/=2){
		while(maxs<p){
			p/=2;
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=p){
				a[i]-=p;
				sum++;
			}else if(sum>=m){
				a[i]=-999;
				if(!f){
					f=1;
					n=i-1;
				}
			}
		}
		if(sum>=m){
			ans+=p;
		}
	}
	cout << ans << endl;
	return 0;
}
