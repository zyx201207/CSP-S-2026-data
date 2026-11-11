#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve3(){
	ll n,d;
	cin>>n>>d;
	vector<ll> pos(n+1,0);
	for(ll i=1;i<=n;i++){
		cin>>pos[i];
	}
	cout<<0<<endl;
	return;
}
void solve2(){
	ll n,d,k,ans=0;
	cin>>n>>d;
	vector<ll> pos(n+1,0);
	for(ll i=1;i<=n;i++){
		cin>>pos[i];
	}
	k=pos[2]-pos[1];
	vector<ll> f(n+1,0);
	f[0]=1; f[1]=1;
	for(ll i=1;i<n;i++){
		ll min_cost=(i*k+(d-1))/d;
		//if((min_cost*d-k*i>=k&&min_cost*d-k*i<2*k)	cout<<"<"<<i<<">";
		ans+=((min_cost*d-k*i>=k&&min_cost*d-k*i<2*k&&min_cost==2)?(n-i):0);
	}
	cout<<ans<<endl;
	return;
}

ll my_abs(ll a){
	return a>=0?a:(-a);
}

void solve1(){
	ll n,d;
	cin>>n>>d;
	vector<ll> pos(n+1,0);
	for(ll i=1;i<=n;i++){
		cin>>pos[i];
	}
	vector< pair<ll,ll> > f(n+1,{1e9,0});
	//f[j].first:i to j min cost
	//f[j].second:i to j number
	ll ans=0;
	for(ll i=1;i<n;i++){
		for(ll j=0;j<=n;j++){
			f[j].first=1e9;
			f[j].second=0;
		}
		f[i].first=0; f[i].second=1;
		for(ll k=i+1;k<=n;k++){
			for(ll t=k-1;t>=i;t--){
				if(pos[k]-pos[t]>d){
					break;
				}
				if(f[k].first>f[t].first+1){
					f[k].first=f[t].first+1;
					f[k].second=f[t].second;
				}else if(f[k].first==f[t].first+1){
					f[k].second+=f[t].second;
				}
			}
			if(f[k].second==2){
				++ans;
				//for(ll k=1;k<=n;k++)	cout<<f[k].first<<","<<f[k].second<<" ";
				//cout<<":"<<i<<","<<j<<";"<<endl;
			}
		}
	}
	cout<<ans<<endl;
	f.clear();
	
	return;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll c=0,t=0;
	cin>>c>>t;
	if(c==13||c==14){
		for(ll i=0;i<t;i++){
			solve3();
		}
	}else if(c==11||c==12){
		for(ll i=0;i<t;i++){
			solve2();
		}
	}else{
		for(ll i=0;i<t;i++){
			solve1();
		}
	}
	
	
	return 0;
}