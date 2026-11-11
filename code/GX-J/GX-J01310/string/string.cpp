#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll n,a,ans,x;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a--) s+=c;
	}
	ll len=s.size();
	while(len--){
		if(s[x]!=s[len]){
			ans++;
			s[len]=s[x];
		} 
		x++;
	}
	cout<<ans;
	return 0;
}
