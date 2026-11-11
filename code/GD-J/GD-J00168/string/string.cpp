#include<bits/stdc++.h>
using namespace std;
using ll=long long;
char s[100000000];
ll n;
int main(){
	freopen("string5.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ll cnt=0;
	for(int i=0;i<n;i++){
		ll len;
		char c;
		cin>>len>>c;
		for(int j=0;j<len;j++){
			s[j+cnt]=c;
		}
		cnt+=len;
	}
	ll ans=0;
	ll cc=cnt/2;
	for(int i=0;i<cc;i++){
		if(s[i]!=s[cnt-i-1]){
			ans++;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
