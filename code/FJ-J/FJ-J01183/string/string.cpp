#include <bits/stdc++.h>
using namespace std;
long long n,a,cnt;
char c;
string s,ss;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a>>c;
		for (int j=1;j<=a;j++) s+=c;
	}
	for (long long i=s.size()-1;i>=0;i--) ss+=s[i];
	if (s==ss){
		cout<<"0\n";
		return 0;
	}
	for (long long i=0;i<s.size();i++){
		if (s[i]!=ss[i]) cnt++;
	}
	cout<<cnt/2<<"\n";
	return 0;
}
