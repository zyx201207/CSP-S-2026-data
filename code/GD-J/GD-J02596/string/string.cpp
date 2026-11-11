#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,l,cnt;
char c;
string s;
bool f;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(ll j=1;j<=a;j++)s+=c;
	}
	l=s.size();
	for(ll i=0;i<l/2;i++)if(s[i]!=s[l-i-1])f=1,cnt++;
	if(!f)cout<<0;
	else cout<<cnt;
	return 0;
}
