#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s="";
ll ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int l;
	cin>>l;
	ll m,L;
	char a;
	while(l--){
		cin>>m>>a;
		for(int i=1;i<=m;i++) s+=a;
	}
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]) ans++;
	}
	cout<<ans;
	return 0;
}
