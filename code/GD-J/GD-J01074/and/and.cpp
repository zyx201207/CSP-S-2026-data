#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[1000005],ma=INT_MIN;
bool vis[1000005];
string to_two(ll a){
	string s;
	while(a>0){
		char c=a%2+'0';
		s=c+s;
		a/=2;
	}
	return s;
}
ll to_ten(string a){
	ll s=0,k=1,len=a.size();
	for(int i=len-1;i>=0;i--){
		s+=(a[i]-'0')*k;
		k*=2; 
	}
	return s;
}
ll yu(ll a,ll b){
	string s=to_two(a),s2=to_two(b),anss;
	ll len1=s.size(),len2=s2.size();
	if(len1>=len2) for(int i=1;i<=len1-len2;i++) s2='0'+s2;
	else for(int i=1;i<=len2-len1;i++) s='0'+s;
	len1=s.size(),len2=s2.size();
	for(int i=0;i<len1;i++){
		if(s[i]=='1'&&s2[i]=='1') anss=anss+"1";
		else anss=anss+"0";
	}
	return to_ten(anss);
}
void dfs(vector<ll> v,ll cd,ll maxx){
	if(cd==m){
		ll d=v[0];
		for(int i=1;i<cd;i++) d=yu(d,v[i]);
		ma=max(ma,d);
		return ;
	}
	for(int i=maxx+1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			vector<ll> tv=v;
			tv.push_back(a[i]);
			dfs(tv,cd+1,i);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and3.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	vector<ll> zlx;
	dfs(zlx,0,0);
	cout<<ma;
	return 0;
}
