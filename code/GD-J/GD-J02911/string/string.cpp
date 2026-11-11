#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll l;
ll n;
ll cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		ll ai;
//		scanf("%lld",&ai);
		cin>>ai;
		l+=ai;
		char cr;
//		scanf("%c",&cr);
		cin>>cr;
		for(int j=1;j<=ai;j++){
			s+=cr;
		}
	}
	for(int i=0;i<=l/2;i++){
		if(s[i]!=s[l-1-i])cnt++;
	}
	printf("%lld",cnt);
	return 0;
}
