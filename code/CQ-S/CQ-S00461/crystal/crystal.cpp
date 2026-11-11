#include<bits/stdc++.h>
#include<bits/extc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
constexpr int N=5e5+5;
ll n,m,a[N];
ll check(ll x){
	ll js=0;
	for(int i=1;i<=n;++i){
		if(a[i]>x){
			js=i-1;
			break;
		}
	}
	if(js==0)js=n;
	ll ks=m,res=0;
	for(int i=js;i>=1;--i){
		if(ks-(x-a[i])>=0){
			ks=ks-(x-a[i]);
			res++;
		}else break;
	}
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=5005){
		ll ks=m;
		ll maxx=0;
		for(int i=1;i<=n;++i){
			ll res=0;
			ks=m;
			for(int j=i;j>=1;--j){
				if(ks-(a[i]-a[j])>=0){
					res++;
					ks-=(a[i]-a[j]);
				}else break;
			}
			maxx=max(maxx,res);
		}
		cout<<maxx<<"\n"; 
		return 0;
	}
	if(a[n]<=105){
		ll maxx=0;
		for(int i=1;i<=105;++i){
			maxx=max(maxx,check(i));
		}
		cout<<maxx<<"\n";
		return 0;
	}
	ll ls=a[2]-a[1],maxx=0;
	for(int i=1;i<=n;++i){
		if((i+1)*i/2*ls<=m)maxx=i+1;
		else break;
	}
	cout<<maxx<<"\n";



	return 0;
}




