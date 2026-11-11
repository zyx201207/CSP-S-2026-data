#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s="";
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,len=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		ll a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
		len+=a;
	}
	for(int i=len-1,j=0;i>=0,j<len;i--,j++){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans/2;
	return 0;
}
