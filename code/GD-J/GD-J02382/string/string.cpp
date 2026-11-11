#include <bits/stdc++.h>
using namespace std;
bool is_re(string s){
	string s1=s;
	reverse(s1.begin(),s1.end());
	return (s1==s);
} 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin >> n;
	for(int i=1;i<=n;i++) {
		long long a;
		char c;
		cin >> a>> c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	long long cnt=0,len=s.length();
	if(is_re(s))cout <<cnt; 
	else{
		for(int i =0;i<len/2;i++){
			if(s[i]!=s[len-i-1])cnt++;
		}
		cout<<cnt;	
	}
	return 0;
}
