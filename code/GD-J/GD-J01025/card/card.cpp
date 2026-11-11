#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=5e5+10;
int n,m,a[N],r[N],o[N],ans[N];
void solve(){
	memset(o,-1,sizeof o);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		r[i]=o[a[i]];
		o[a[i]]=i;
	}
	for(int l=1;l<=n;l++){
		for(int i=l;i<=n;i++){
			if(r[i]!=-1){
				i=r[i]-1;
			}else{
				ans[a[i]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int _=1;
	//cin>>_;
	for(int i=1;i<=_;i++){
		solve();
	}
	return 0;
}
