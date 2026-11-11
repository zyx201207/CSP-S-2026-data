#include<bits/stdc++.h> 
using namespace std;
using ll = long long;
ll n,a[10001000],ans; 
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
		char x;
		cin>>x;
		s+=x;
	}
	ll l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]){
			ans+=min(a[l],a[r]);
			if(a[l]<a[r])a[r]-=a[l],l++;
			else if(a[l]>a[r])a[l]-=a[r],r--;
			else r--,l++;	
		}
		else {
			if(a[l]<a[r])a[r]-=a[l],l++;
			else if(a[l]>a[r])a[l]-=a[r],r--;
			else ans+=0,r--,l++;
		}
	}
	cout<<ans;
	return 0;
}
