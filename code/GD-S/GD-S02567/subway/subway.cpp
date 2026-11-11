#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,n,m,d,q,w[500002],r[500002][2],t[500002][2],fi[500002]; 
void line(){
	for(ll j=1;j<=m;j++){
		for(ll i=0;i<n;i++){
			if(r[i][0]==j)fi[j]=i;
		}
	}
	return ;
}
void f(ll s,ll e){
	ll ans=0;
	ans+=w[s-1];
	ll li;
	while(s!=e){
		li=fi[s];
		ans+=t[s-1][0]+t[s-1][1];
		s=r[li][1];
	}
	ans+=w[s-1];
	cout<<ans<<"\n";
	return ;
}
int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=0;i<m;i++)cin>>w[i];
	for(ll i=0;i<n;i++){
		int o;cin>>o;
		cin>>r[i][0]>>t[i][0];
		cin>>r[i][1]>>t[i][1];
	}
	line();
	for(ll i=0;i<q;i++){
		ll s,e;
		cin>>s>>e;
		if(s<e)
			f(s,e);
		else
			f(e,s);
	}
	return 0;
}

