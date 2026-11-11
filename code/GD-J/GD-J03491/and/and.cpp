#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+10;
ll n,m,ar[N],ans;
string to_2(ll x){
	string s="";
	while(x!=0){
		if(x%2==1){
			s+='1';
		}
		else{
			s+='0';
		}
		x/=2;
	}
	reverse(s.begin(),s.end());
	return s;
}
bool cmp(ll a,ll b){
	string c=to_2(a),d=to_2(b);
	ll sum1=0,sum2=0;
	for(ll i=0;i<c.size();i++){
		if(c[i]=='1') sum1++;
	}
	for(ll i=0;i<d.size();i++){
		if(d[i]=='1') sum2++;
	}
	return sum1>=sum2;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>ar[i];
	}
	sort(ar+1,ar+1+n,cmp);
	ans=ar[1];
	for(ll i=1;i<=m;i++){
		ans=ans&ar[i];
	}
	cout<<ans;
	return 0;
}
