#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll n,d,a[2000010],ans=0;
void solve(ll w){
	if(w+3>=n) return;
	//cout<<"w:"<<w<<endl;
	/*if(w+3<n){
		if((a[w+3]-a[w]>d)&&(a[w+3]-a[w]<2*d)){
			ans+=1;
			ll ww=w;
	while(a[ww+1]-a[ww]==d){
		ww+=1;
		ans+=1;
	}
		}
	}*/
	ll f=w+1;
	while(a[f]-a[w]<=d&&f<n){
		f+=1;
	}
	if(a[f]-a[f-1]<d){
		ans+=1;
		ll ww=w;
		while(a[ww+1]-a[ww]==d){
		   ww+=1;
		   ans+=1;
	    }
	}
	w+=1;
	solve(w);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==13||c==14){
		for(int T=0;T<t;T++){
		ans=0;
		cin>>n>>d;
		for(ll i=0;i<n;i++) cin>>a[i];
		if(d<a[2]-a[0]) cout<<"0";
		else{
			solve(0);
		}
		cout<<ans<<endl;
	    }
        }
		
	}
	else{
	
	for(int T=0;T<t;T++){
		ans=0;
		cin>>n>>d;
		for(ll i=0;i<n;i++) cin>>a[i];
		solve(0);
		cout<<ans<<endl;
	}
}
	return 0;
}

