#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s,x;
ll ans,n,b;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
    	cin>>b>>x;
    	for(ll j=1;j<=b;j++)s+=x;
	}
	ll len=s.size();
	ll l=0,r=len-1;
	while(l<=r){
		if(s[l]!=s[r])ans++;
		l++;r--;
	}
	cout<<ans;
	return 0;
} 
