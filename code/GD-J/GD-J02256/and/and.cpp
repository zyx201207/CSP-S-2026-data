#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
const ll MAXN=2e5+5;
ll n,m;
ll a[MAXN],maxx,sum;
map<ll,ll> mp;
bool teshu1=true,teshu2=true;
void init(){
	ll cur=1;
	mp[cur]=1;
	for(int i=1;i<=30;++i){
		cur*=2;
		mp[cur]=1;
	}
	return ;
}
ll cal(ll mask){
	ll res;
	for(int i=0;i<n;++i){
		if(mask&(1<<i)){
			res=a[i+1];
			break;
		}
	}
	for(int i=0;i<n;++i){
		if(mask&(1<<i)){
			res=res&a[i+1];
		}
	}
	return res;
}
bool cmp(pair<ll,ll> a,pair<ll,ll> b){
	return a.fi>b.fi;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(mp[(a[i]+1)]!=1){
			teshu1=false;
		}
		if(a[i]!=i-1){
			teshu2=false;
		}
	}
	init();
	if(n<=20){
		ll ans=0;
		for(int i=0;i<(1<<n);++i){
			if(__builtin_popcount(i)==m){
				//cout<<ans<<'\n';
				ans=max(ans,cal(i));
			}
		} 
		cout<<ans;
	}
	else if(m==1){
		cout<<maxx;
	}
	else if(m==n){
		ll sum=a[1];
		for(int i=1;i<=n;++i){
			sum=(sum&a[i]);
		}
		cout<<sum;
	}
	else if(m==2){
		ll ans=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(i==j){
					continue;
				}
				ans=max(ans,a[i]&a[j]);
			}	
		}
		cout<<ans;
	}
	else if(m==n-1){
		//sum=a[1];
		vector<pair<ll,ll> > cur;
		for(int i=1;i<=n;++i){
			cur.push_back({__builtin_popcount(a[i]),i});
		}
		sort(cur.begin(),cur.end(),cmp);
		sum=a[cur[0].se];
		for(int i=0;i<cur.size()-1;++i){
			sum=(sum&a[cur[i].se]);
		}
		cout<<sum;
	}
	else if(teshu1){
		cout<<maxx;
	}
	else if(maxx<=4){
		map<ll,ll> mp2;
		mp2.clear();
		for(int i=1;i<=n;++i){
			mp2[a[i]]++;
		}
		if(m==1){
			for(int i=4;i>=0;--i){
				if(mp2[i]){
					cout<<i;
					break;
				}
			}
		}
		else{
			if(mp2[4]>=2){
				cout<<4;
			}
			else if(mp[3]>=1&&mp[4]>=1){
				cout<<3;
			}
			else if(mp[3]>=2){
				cout<<3;
			}
			else if(mp[2]>=2){
				cout<<2;
			}
			else if(mp[4]>=1&&mp[2]>=1){
				cout<<2;
			}
			else{
				cout<<0;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
4 2
3 15 12 12
*/
