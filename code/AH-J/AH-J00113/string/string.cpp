#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans,t;
char ch;
string str,str1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll len=0;
	for(int i=1;i<=n;i++){
		cin>>t>>ch;
		len+=t;
		while(t--){
			str+=ch;
		}
	}
	str1=str;
	reverse(str1.begin(),str1.end());
	if(str1==str){
		cout<<0;
		return 0;
	}
	for(ll i=0;i<len;i++){
		if(str[i]!=str1[i]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
