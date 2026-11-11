#include<bits/stdc++.h>
using namespace std;
string s;
long long x,n,r,l,ans;
char a;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>x>>a;
		r+=x;
		while(x--) s+=a;
	}
	r-=1;
	while(l<r){
		if(s[l]!=s[r]) ans++;
		l++,r--;
	}
	cout<<ans; 
	return 0;
}
