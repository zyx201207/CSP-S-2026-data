#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200010],maxlen,flag[200010];
string s[200010];
string turn(ll a){
	string ans;
	ll tot=0;
	while(a){
		ans.push_back(char(a%2+'0'));
		a/=2;
		tot++;
	}
	maxlen=max(maxlen,tot);
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		s[i]=turn(a[i]);
	}
	string ans1="0";
	for(ll i=maxlen-1;i>=0;i--){
		ll cnt=0;
		for(ll j=1;j<=n;j++){
			if(!flag[j]&&s[j].size()>i&&s[j][i]=='1') cnt++;
		}
		if(cnt<m) ans1.push_back('0');
		else{
			ans1.push_back('1');
			for(ll j=1;j<=n;j++){
				if(s[j].size()<=i||s[j][i]=='0') flag[j]=1;
			}
		}
	}
	ll sumans=0,powe=1;
	for(ll i=ans1.size()-1;i>=0;i--){
		sumans+=powe*(ans1[i]-'0');
		powe*=2;
	}
	cout<<sumans<<' ';
	return 0;
}
