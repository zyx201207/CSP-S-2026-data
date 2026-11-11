#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s=" ";
	ll m=0;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		m+=a;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	ll cnt=0,m1=m;
	m/=2;
	for(ll i=1;i<=m;i++){
		if(s[i]!=s[m1+1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
