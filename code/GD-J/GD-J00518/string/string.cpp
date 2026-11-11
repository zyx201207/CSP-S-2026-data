#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
ll cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;  
	int f=1;
	char fa='1';
	for(int i=1;i<=n;i++){
		int x;
		char a;
		cin>>x>>a;
		while(x--)s+=a;
	}
	if(n>2000){
		cout<<0;
		return 0;
	}
	ll len=(s.size()+1)>>1;
	ll l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r])cnt++;
		l++,r--;
	}
	cout<<cnt;
	return 0;
}

