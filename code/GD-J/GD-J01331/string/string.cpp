#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,a,ans;
char c;
string s;
int main(){
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++) s+=c;
	}
	for(int i=0;i<s.length()/2;i++) if(s[i]!=s[s.length()-i-1]) ans++;
	cout<<ans;
	
	return 0;
}
