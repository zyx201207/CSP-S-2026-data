#include <bits/stdc++.h>
#define int long long
const int N=2e5+10;
using namespace std;
int n,m,a[N],ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
 	ios::sync_with_stdio(0);
 	cin.tie(0),cout.tie(0);
 	cin>>n>>m;
 	for(int i=1;i<=n;i++){
 		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<int>());
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
	}else{
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans=(ans&a[i]);
		}
		cout<<ans;
	}
	return 0;
}
