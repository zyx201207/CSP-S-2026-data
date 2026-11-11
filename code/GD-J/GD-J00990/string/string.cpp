#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n,a[200005],sum;
char c[200005];
string s;
ll chayi(const string& t){
	ll ans=0;
	for(int i=0;i<t.size();i++)ans+=s[i]!=t[i];
	return ans;
}
ll left(){
	ll ans=0;
	if(sum&1)ans=chayi(s.substr(0,sum/2)+s[sum/2]+s.substr(0,sum/2));
	else ans=chayi(s.substr(0,sum/2)+s.substr(0,sum/2));
	return ans;
}
ll right(){
	ll ans=0;
	if(sum&1)ans=chayi(s.substr(sum/2+1,sum/2)+s[sum/2]+s.substr(sum/2+1,sum/2));
	else ans=chayi(s.substr(sum/2,sum/2)+s.substr(sum/2,sum/2));
	return ans;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++)sum+=a[i];
	for(int i=1;i<=n;i++)while(a[i]--)s+=c[i];
	cout<<min(left(),right());
	return 0;
} 
