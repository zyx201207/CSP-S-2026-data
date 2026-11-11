#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN=1e6+5;
ll c,t,n,k,cnt[MAXN],ans=1;
struct add{
	ll u,v;
}a[MAXN];
bool cmp(add a,add b){
	return a.u>b.u;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c>>t;
	while(t--){
		ans=1;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i].u>>a[i].v;
			cnt[a[i].u]++;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(cnt[a[i].u]>1) ans+=cnt[a[i].u];
		}
		cout<<ans<<endl; 
	}
	return 0;
}
