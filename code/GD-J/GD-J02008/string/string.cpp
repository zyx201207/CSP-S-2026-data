#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1;
ll a;
ll s2[300000];
int main(){
	freopen("string.in","r",stdin);
	ll n;
	cin>>n;
	ll ans =0;
	ll num=0;
	for(int i=0;i<=n-1;i++){
		char t;
		ll a;
		cin>>a;
		num+=a;
		s2[i] = a;
		cin>>t;
		s1+=t;
	}
	
	ll l=0,r=n-1;
	int cishu=1;
	for(int i=0;i<=n-1;i++)
	while(l<r){
		if(s1[l]!=s1[r]){
			if(s2[l]>s2[r]){
				s2[l] -=s2[r];
				ans+=s2[r];
				r--;
				
				
			}
			if(s2[l] == s2[r]){
				ans+=s2[l];
				//cout<<l<<" "<<r<<" "<<cishu<<endl;
				l++;
				r--;
				
				
			}
			if(s2[l] <s2[r]){
				s2[r] -=s2[l];
				ans+=s2[l];
				l++;
				
			}
		}
		if(s1[l]==s1[r]){
			if(s2[l]>s2[r]){
				s2[l]-=s2[r];
				r--;
			}
			if(s2[l]==s2[r]){
				l++;
				r--; 
			}
			if(s2[l]<s2[r]){
				s2[r]-=s2[l];
				l++;
				
			}
		}
		cishu++;
	}
	
	cout<<ans<<endl;
	freopen("string.out","w",stdout);
	return 0;
}
