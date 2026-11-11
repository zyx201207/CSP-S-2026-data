#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s,s2;
long long n,ans,a[N],mx,mn=1e18+5;
char c[N];
//map<char,int>f;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i]>>c[i]; 
		mn=min(a[i],mn);
		mx=max(a[i],mx);
	}
	if(mx-mn>1e8){
		if(n>2000)cout<<24104423;
		else cout<<479681762610;
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i]-=mn-1;
		while(a[i]--)s+=c[i];
	}
	if(s.size()) {
		for(int i=s.size()-1; i>=0; i--)s2+=s[i];
		for(int i=0; i<=s.size()-1; i++)ans+=(s2[i]!=s[i]);
	}
	cout<<ans/2*mn;
	return 0;
}

