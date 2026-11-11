#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll n,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	while(n--){
		ll a;
		string s1;
		cin>>a>>s1;
		for(int i=1;i<=a;i++) s+=s1;	
	}
	ll m=s.size();
	if(m%2==1){
		for(int i=m/2-1;i>=0;i--){
			if(s[i]!=s[m-i-1]){
				ans++;
			}
		}
	}
	else if(m%2==0){
		for(int i=m/2-1;i>=0;i--){
			if(s[i]!=s[m-i-1]){
				ans++;
			}
		}	
	}
	cout<<ans;
	return 0;
}
