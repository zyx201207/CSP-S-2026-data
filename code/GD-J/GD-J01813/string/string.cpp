#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
int n,a[200005],sum,x,y,ans;
char b[200005];
vector<pair<int,char>>v1,v2;
pair<int,char>tmp;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i],sum+=a[i];
	if(n==1) return cout<<0,0;
	x=sum>>1;
	for(int i=1;i<=n;i++){
		if(a[i]<=x) v1.push_back({a[i],b[i]}),x-=a[i];
		else{
			if(x) v1.push_back({x,b[i]});
			break;
		}
	}
	x=sum>>1;
	for(int i=n;i>=1;i--){
		if(a[i]<=x) v2.push_back({a[i],b[i]}),x-=a[i];
		else{
			if(x) v2.push_back({x,b[i]});
			break;
		}
	}
//	for(auto x:v1) cout<<x.fi<<','<<x.se<<' ';cout<<'\n';
//	for(auto x:v2) cout<<x.fi<<','<<x.se<<' ';cout<<'\n';
	int l=0,r=0;
	x=0,y=0;
	while(l<v1.size()||r<v2.size()){
		if(x<=y){
			if(v1[l].se!=tmp.se) ans+=min(v1[l].fi,tmp.fi);
			if(v1[l].fi>tmp.fi) tmp={v1[l].fi-tmp.fi,v1[l].se};
			else tmp.fi-=v1[l].fi;
			x+=v1[l].fi;
			l++;
		}
		else{
			if(v2[r].se!=tmp.se) ans+=min(v2[r].fi,tmp.fi);
			if(v2[r].fi>tmp.fi) tmp={v2[r].fi-tmp.fi,v2[r].se};
			else tmp.fi-=v2[r].fi;
			y+=v2[r].fi;
			r++;
		}
	}
	cout<<ans;
	return 0;
}

