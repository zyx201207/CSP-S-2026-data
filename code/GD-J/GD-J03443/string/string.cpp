#include<iostream>
#include<vector>
using namespace std;
using ll=long long;
#define pf printf
#define f(i,j,k) for(ll i=j;i<=k;i++)
#define F(i,j,k) for(ll i=j;i>=k;i--)
#define pb push_back
#define st first
#define nd second
inline void R(ll&x){scanf("%lld",&x);}
ll n,x,p;
vector<pair<ll,char>>v;
int main(){
	freopen("string.in","r",stdin),freopen("string.out","w",stdout);
	R(n);
	f(i,1,n){
		ll a;
		char b;
		R(a),cin>>b,v.pb({a,b});
	}p=n-1;
	ll i=0;
	for(auto a:v){
		ll st=a.st,nd=a.nd;
		while(st){
			if(v[p].nd!=nd){
				x+=min(v[p].st,st);
				if(v[p].st>st)v[p].st-=st,st=0;
				else st-=v[p].st,v[p].st=0,p--;
			}else st-=v[p].st,v[p].st=0,p--;
			if(p==i)break;
		}i++;
	}pf("%lld",x);
	return 0;
}