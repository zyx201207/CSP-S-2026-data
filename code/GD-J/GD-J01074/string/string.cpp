#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m[1000005],ans;
char a[1000005];
string s,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll ma=0;
	for(ll i=1;i<=n;i++) cin>>m[i]>>a[i];
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m[i];j++) s=s+a[i];
	}
	ll len=s.size();
	for(int i=0,j=len-1;i<=j;i++,j--){
		if(s[i]!=s[j]) ans++; 
	}
	cout<<ans;
	return 0;
}
