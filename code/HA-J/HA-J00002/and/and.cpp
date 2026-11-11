#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,m,a[N],ans;bool del[N];
#define fre(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
signed main(){
	fre("and");
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int k=29;~k;--k){
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(del[i])continue;
			if((a[i]>>k)&1)++cnt;
		}
		if(cnt>=m){
			ans|=1<<k;
			for(int i=1;i<=n;++i)if(!((a[i]>>k)&1))del[i]=1;
		}
	}
	cout<<ans;
	return 0;
}
