#include<bits/stdc++.h>
using namespace std;
long long n,s;
string s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long a;
		char c;
		cin>>a>>c;
		for(long long i=1;i<=a;i++) s1+=c;
	}
	for(long long i=s1.size()-1;i>=0;i--) s2+=s1[i];
	for(long long i=0;i<s1.size()/2;i++){
		if(s1[i]!=s2[i]) s++;
	}
	cout<<s;
	return 0;
}
