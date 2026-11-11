#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N(2e5+5);
int n,m,ans;
int a[N],ban[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int j=29;~j;--j){
		int cnt(0);
		for(int i=1;i<=n;++i) if(a[i]>>j&1 and !ban[i]) cnt++;
		if(cnt>=m){
			ans+=1<<j;
			for(int i=1;i<=n;++i) if(a[i]>>j&1^1) ban[i]=1;
		}
	}
	cout<<ans;
}
