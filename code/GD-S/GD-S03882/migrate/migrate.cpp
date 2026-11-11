#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=307,INF=1E17;
	ll c,t,n,d,x[N];
	pair<ll,ll> r[N][N];
void chk(ll a){
	// cout<<"!"<<a<<" ";
	ll cnt=0;
	ll u=0,st=-1;
	ll lst=-1;
	while(a!=0){
		u++;
		lst=u;
		if(a&1==0){
			a/=2;
			continue;
		}
		cnt++;
		if(lst==-1){
			lst=st=u;
			a/=2;
			continue;
		}
		if(abs(x[lst]-x[u])>d){
			// cout<<lst<<":"<<u<<endl;
			return;
		}
		a/=2;
		// cout<<a<<" "<<cnt<<endl;
	}
	// cout<<lst<<" "<<st<<" "<<cnt<<" "<<r[st][lst].second<<endl;
	if(lst==-1||st==-1) return;
	if(cnt<r[st][lst].first)
		r[st][lst]={cnt,1};
	else if(cnt==r[st][lst].first)
		r[st][lst].second++;
}
int main(){
	freopen("D:\\csps-new\\down\\migrate\\migrate2.in","r",stdin);
		// freopen("migrate.in","r",stdin);
		// freopen("migrate.out","w",stdout);
		cin>>c>>t;
	while(t--){
			cin>>n>>d;
			ll ans=0;
			for(ll i=1;i<=n;i++)
				cin>>x[i];
			// memset(r,0,sizeof r);
			for(ll i=0;i<=n;i++)
				for(ll j=0;j<=n;j++)
					r[i][j]={INF,0};
		ll a=0;
		while(true){
			chk(a);
			a++;
			// if(a==9) cout<<"!"<<endl;
			if(a&(1<<(n))) break;
		}
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				if(r[i][j].second==2){
					ans++;
					// cout<<i<<" "<<j<<endl;
				}
			}
		}
		// cout<<r[1][4].second<<endl;
		cout<<ans<<endl;
	}
	
	return 0;
}
