#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct str{
	ll n;
	string s;
};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,t=0,ans=0,f=1,l,r;
	cin>>n;
	vector<str>s(n+1);
	for(ll i=1;i<=n;i++){
		cin>>s[i].n;
		cin>>s[i].s;
		t+=s[i].n;
		if(s[i].s!=s[i-1].s&&i!=1)
			f=0;
	}
	if(f){
		cout<<0;
		return 0;
	}
	l=1;
	r=n;
	while(l<=r){
		//cout<<l<<" "<<r<<" "<<s[l].s<<","<<s[r].s<<" "<<ans<<endl;
		if(s[l].s!=s[r].s){
			if(s[l].n==s[r].n){
				ans+=s[l].n;
				l++,r--;
			}
			else{
				if(s[l].n>s[r].n){
					s[l].n-=s[r].n;
					ans+=s[r].n;
					r--;
				}
				else{
					s[r].n-=s[l].n;
					ans+=s[l].n;
					l++;
				}
			}
		}else{
			if(s[l].n>s[r].n){
				s[l].n-=s[r].n;
				r--;
			}
			else if(s[l].n<s[r].n){
				s[r].n-=s[l].n;
				l++;
			}
			else{
				l++,r--;
			}
		}
		
	}
	cout<<ans;
	return 0;
}
