#include <bits/stdc++.h>
using namespace std;
long long n,x,ans;
char a;
string s;
void d(string s){
	long long l=0,r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]) ans++;
		l++,r--;
	}
}
int main(){
	freopen("stirng.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) {
		cin>>x>>a;
		while(x--) s+=a;
	}
	d(s);
	cout<<ans;
	return 0;
} 
