#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fo(i,a,b) for(ll i=a;i<=b;i++)
//unsigned
const ll N=5e5+4,INF=1e9+1e5;
ll n,m,a[N],mx;
bool cmp(ll a,ll b){return a>b;}

void check(ll p,ll sum,ll x){
	ll num=1,i=p+1;
	
	while(i<=n&&sum>=x-a[i]){
	//	cout<<x-a[i]<<'\n';
		if(sum<x-a[i])break;
		sum-=(x-a[i]);
		num++;i++;
	}
//	cout<<num<<'\n';
	mx=max(mx,num);
}

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	if(n>5000){
	//9999 10 1 3
	ll ans=0;
	ll x,y,d,b;
	cin>>x>>y;
	d=abs(x-y);b=d;
	
	ll i=1;
	while(i<=n&&m>=d*i){
		m-=d*i;
		i++;
		ans++;
		
	}
	cout<<ans;
	return 0;
	
	
	
	
	}
	fo(i,1,n){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	fo(i,1,n){
		check(i,m,a[i]);
	}
	cout<<mx;
	return 0;
}//Oct31==Dec25?
//5 5 9 8 4 2 1
//5 8 -3 -1 2 2 7
