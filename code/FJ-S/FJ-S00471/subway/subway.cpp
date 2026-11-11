#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> s[500005];
ll t[500005],match[500005],tim[500005];
bool h[500005];
ll minn=10000000;
void check(ll num,ll re,ll all,bool l[500005]){
	for(int i=1;i<=s[num].size();i++){
		if(all>minn)return ;
		if(s[num][i]==re){
			minn=min(minn,all);
			return ;
		}
		else if(h[i]==0){
			h[i]=1;
			check(s[num][i],re,all+tim[s[num][i]],l);
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	ll c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	if(c>=7 && c<=11){
		for(int i=1;i<=m;i++)cin>>t[i];
		for(int i=1;i<=n;i++)
		{
			ll kk; 
			cin>>kk; 
			ll u1,u2,v1,v2; 
			cin>>u1>>v1>>u2>>v2; 
			s[u1].push_back(u2); 
			s[u2].push_back(u1); 
			tim[u1]+=v1,tim[u2]+=v2; 
		} 
		while(q--) 
		{ 
			minn=100000000; 
			int l,r; 
			cin>>l>>r; 
			check(l,r,0,h); 
			cout<<minn<<endl; 
		} 
	} 
	return 0; 
} 
