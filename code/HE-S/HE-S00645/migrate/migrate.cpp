#include <bits/stdc++.h>
using namespace std;

int t;
const int maxn=2e6+5;
int n,d,a[maxn];
int nxt(int now){
	return upper_bound(a,a+n,a[now]+d)-a-1;
}
int dis(int x,int y){//O(n)
	int now=x;
	int ans=0;
	while(now<y){
		if(nxt(now)==now){
			return 114514;
		}
		now=nxt(now);
		++ans;
	}
	return ans;
}
void solve(){
	cin>>n;
	cin>>d;
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	int ans=0;
	for(int i=0;i<n;++i){
		int start=nxt(i);
		for(int j=i+3;j<n;++j){//O(n^3);
			if(dis(i,j)==dis(start-1,j)+1 && dis(start-1,j)!=dis(start-2,j)){
				++ans;
			}
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n;
	cin>>t;
	while(~--t){//(O(tn^3)
		solve();
	}
}
