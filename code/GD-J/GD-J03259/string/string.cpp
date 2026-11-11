#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fin(x) freopen(x".in","r",stdin);
#define fop(x) freopen(x".out","w",stdout);
#define IO(x) fin(x)fop(x)
ll n,ans;
struct a{
	ll num;
	char x;
}s[200005];
int main(){
	IO("string")
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>s[i].num>>s[i].x;
	}
	ll r=0,l=n-1;
	while(r<l){
		if(s[r].x==s[l].x){
			if(s[r].num>s[l].num){
				s[r].num-=s[l].num;
				l--;
			}
			else if(s[r].num<s[l].num){
				s[l].num-=s[r].num;
				r++;
			}
			else {
				l--;
				r++;
//				cout<<l<<' '<<r<<'\n';
			}
		}
		else{
			if(s[r].num>s[l].num){
				s[r].num-=s[l].num;
				ans+=s[l].num;
				l--;
			}
			else if(s[r].num<s[l].num){
				s[l].num-=s[r].num;
				ans+=s[r].num;
				r++;
			}
			else {
				ans+=s[l].num;
				l--;
				r++;
			}
		}
	}
	cout<<ans;
	return 0;
}
