#include <bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
string s;
bool p(string s){
	string f=s;
	reverse(f.begin(),f.end());
	return f==s;
}
long long r(string s,long long len){
	for (long long i=len/2;i<len;i++){
		if (s[i]!=s[len-i-1])return i;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		string ss(a[i],c[i]);
		s+=ss;
	}
	long long len=s.size();
	while(!p(s)){
		long long b=r(s,len);
		s[b]=s[len-b-1];
		ans++;
	}
	cout<<ans<<endl;
	return 0;
}
