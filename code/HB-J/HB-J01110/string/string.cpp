#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,n,ans;
string s="";
//ToT
//orz
//ORZ
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll x;
		cin>>x;
		l+=x;
		char c;
		cin>>c;
		while(x--) s+=c; 
	}
	//string ss=reserve(s.begin(),s.end());
	//if(s==ss){
	//	cout<<0;
	//	return 0;
	//}
	if(l%2){
		for(int i=0;i<(l+1)/2;i++){
			if(s[i]!=s[l-1-i]) ans++;
		}
		cout<<ans;
	}
	else{
		for(int i=0;i<(l)/2;i++){
			if(s[i]!=s[l-1-i]) ans++;
		}
		cout<<ans;
	}
	
	return 0;
}
//10000ge a
//10000ge b
//10000ge c
