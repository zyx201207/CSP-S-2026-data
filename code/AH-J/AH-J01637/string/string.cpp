#include<bits/stdc++.h>
using namespace std;
unsigned long long ans=0;
int n,ji;
long long num[200005],fast,slow,last;
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i]>>c[i];
		for(int j=1;j<=num[i];j++){
			s+=c[i];
		}
	}
	fast=0,slow=s.length()-1;
	for(auto i=0;i<s.length();i++){
		if(s[fast]!=s[slow]) ans++;
		fast++;
		slow--;
	}
	cout<<ans/2;
	return 0;
}

