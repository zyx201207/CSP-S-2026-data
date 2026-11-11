#include <bits/stdc++.h>
using namespace std;
long long n,a,cnt,c;
string s,ts;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		char x;
		cin>>a>>x;
		c+=a;
		while(a--)s+=x;
	} 
	for(long long j=s.size()-1;j>=0;j--)ts+=s[j]; 
	if(s==ts){
		cout <<0;
		return 0;
	} 
	for(long long i=0;i<floor(c/2);i++){
		int j=0;
			if(s[i]!=ts[j++])cnt++;
	} 
	cout <<cnt;
	return 0;
}
