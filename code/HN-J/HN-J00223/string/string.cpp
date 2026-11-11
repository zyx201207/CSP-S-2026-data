#include "bits/stdc++.h"
using namespace std;
long long n,ans,a[200005];
char c[200005];
map<char,long long> mp; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		mp[c[i]]++;
	}
	if(n/2!=0){
		for(int i=0;i<n/2;i++){
			if(c[i]==c[n-i-1]&&a[i]==a[n-i-1])continue;
			else ans+=a[i];
		}
	}
	else {
		for(int i=0;i<n/2-1;i++){
			if(c[i]==c[n-i-1]&&a[i]==a[n-i-1])continue;
			else ans+=a[i];
		}
	}
	for(int i=0;i<n;i++){
		if(mp[c[i]]==n){
			cout<<0;
			break;
		}
		else {
			cout<<ans;
			break;
		}
		
	}
}
