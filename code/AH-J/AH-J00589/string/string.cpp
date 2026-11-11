#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
string s;
char c;
ll a;
ll ans;
void pj(ll a,char c){
	while(a--){
		s=s+c;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		pj(a,c);
	}
	string t=s;
	reverse(t.begin(),t.end());
	if(s==t){
		cout<<0;
		return 0;
	}
	ll l=(s.size())/2;
	ll len=s.size();
	string s1=s.substr(0,l);
	string s2=s.substr(len-1-l+1,len-1);
	if(len%2==1){
		for(int i=0;i<l;i++){
			if(s[i]!=s[i+l+1]){
				ans++;
			}
		}
	}else{
		for(int i=0;i<l;i++){
			if(s[i]!=s[i+l])ans++;
		}
	}
	cout<<ans;
	return 0;
}
