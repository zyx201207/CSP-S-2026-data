#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	ll n,i;
	cin>>n;
	while(n--){
		cin>>i;
		char c;
		cin>>c;
		while(i--){
			s=s+c;
		}
	}bool flag=1,ans=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			flag=0;
			ans++;
		}
	}cout<<ans;
	return 0;
}
