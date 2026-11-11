#include<bits/stdc++.h>
#define ci const int
#define ll long long int
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string s="",t;
	ll n,ans=0;
	cin >> n;
	while(n--){
		ll a;
		string t;
		cin >> a >> t;
		for(int i=1;i<=a;i++){
			s+=t;
		}
	} 
	t=s;
	reverse(s.begin(),s.end());
	if(s==t){
		cout << 0;
		return 0;
	}
	ll cspj=s.size(),csps=t.size(),cnt=0;
	while(s!=t){
		if(s[cnt]!=t[cnt]){
			s[cnt]=t[cnt];
			t[csps-cnt-1]=s[cnt];
			cnt++;
			ans++;
		}
	}
	cout << ans;
} 
