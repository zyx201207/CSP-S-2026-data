#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e6+10;
ll ccc,t,n,d,a[N],b[N],c[N];
struct E{
	ll st,id;
};
queue<E> q;
void BFS(){
	ll sp=q.front().st;
	ll di=q.front().id;
	q.pop();
	if(b[di]==sp){
		c[di]++;
		if(c[di]>2) return;
	}
	if(b[di]<sp) return;
	if(b[di]>sp){
		b[di]=sp;
		c[di]=1;
	}
	for(ll i=di+1;i<=n&&a[di]+d>=a[i];i++){
		q.push({sp+1,i});
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>ccc>>t;
	while(t--){
		cin>>n>>d;
		bool p=1;
		ll ch=0,ans=0;
		for(ll i=1;i<=n;i++){
			cin>>a[i];
			if(i==2){
				ch=a[i]-a[i-1];
			}else{
				if(i!=1&&a[i]-a[i-1]!=ch) p=0;
			}
		}
		if(p){
			if(d<ch*2) cout<<"0\n";
			else{
				ll k=d/ch;
				cout<<max(n-(2ll*k)+1ll,0ll)<<"\n";
			}
			continue;
		}
		for(ll i=1;i<n;i++){
			for(ll i=1;i<=n;i++){
				b[i]=c[i]=0;
			}
			q.push({0,i});
			while(!q.empty()){
				BFS();
			}
			for(ll i=1;i<=n;i++){
				if(c[i]==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}//Good Luck!
