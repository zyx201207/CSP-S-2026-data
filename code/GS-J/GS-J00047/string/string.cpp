#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s = "";
	while(n--){
		char c;
		long long d;
		cin>>d>>c;
		while(d--) s += c;
	}
	long long a = 0;
	for(long long i = 0;i*2<s.size();i++){
		if(s[i]!=s[s.size()-1-i]) a++;
	}
	cout<<a;
	return 0;
}
