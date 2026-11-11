#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll a;char c; 
string s;
ll len;
ll ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	while(n--){
		cin>>a>>c;
		len+=a;
		while(a--){
			s+=c;
		}
	}
	string x=s;
	reverse(s.begin(),s.end());
	if(x==s) {
		cout<<0<<'\n';
		return 0;
	}
	for(int i=1;i<=len;i++){
		if(i-1==len+1-i-1){
			break;
		}
		if(s[i-1]!=s[len-i]){
			ans++;
		}
	}cout<<ans;
	return 0;
} 
