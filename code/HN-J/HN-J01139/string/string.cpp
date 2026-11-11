#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	long long n,cw = 0,x = 0;
	cin>>n;
	for(long long i = 0;i < n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(long long j = 0;j < a;j++){
			s = c + s;
		}
	}
	for(long long l = 0,r = s.size();r >= l;r--,l++){
		if(s[r] == s[l])x++;
		else{
			cw++;
		}
	}
	cout<<cw - 1;
	return 0;
} 
