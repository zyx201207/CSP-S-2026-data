#include<bits/stdc++.h>
#define ll long long
#define FR(a,b,c) for(ll a=b;a<=c;++a)
#define RF(a,b,c) for(ll a=b;a>=c;--a)
using namespace std;
const int N=2e5;
int n,m,ans,q,g[N];
vector<ll> a(N);
vector<ll> s[N];
void e(ll x){
	int idx=0,b=x;
	while(b){
		idx++;
		g[idx]+=b%2;
		if(b&1)s[idx].push_back(x);
		b/=2;
	}
	return;
}
void et(ll x){
	int idx=0,b=x;
	while(b){
		idx++;
		g[idx]+=b%2;
		b/=2;
	}
	return;
}
int mi(ll x,ll ci){
	ll p=x;
	FR(i,1,ci)p*=x;
	return p;
}
int w(ll x){
	int idx=0;
	while(x){
		idx++;
		x>>=1;
	}
	return idx;
}
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	FR(i,1,n){
		cin>>a[i-1];
		e(a[i-1]);
	}
	sort(a.begin(),a.end(),cmp);
	ll mx=w(a[0]);
	while(mx){
		sort(a.begin(),a.end(),cmp);
		RF(i,mx,1){
			if(g[i]>=m){
				mx=i-1;
				ans+=mi(2,i);
				a.clear();
				FR(k,0,s[i].size()-1){
					a.push_back(s[i][k]);
				}
				FR(k,0,31)g[k]=0;
				FR(k,1,a.size())et(a[k-1]);
				break;
			}
			if(i==1)mx=0;
		}
	}
	cout<<ans;
	return 0;
}
