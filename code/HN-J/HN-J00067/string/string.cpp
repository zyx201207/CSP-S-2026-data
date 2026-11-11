#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
string s=" ";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long l=0;
	while(n--){
		long long a;
		char c;
		cin>>a;
		cin>>c;
		l+=a;
		while(a--)s+=c;
	}
	for(long long i=1;i<=l/2;i++){
		if(s[i]!=s[l+1-i])cnt++;
	}
	cout<<cnt;
	return 0;
}
