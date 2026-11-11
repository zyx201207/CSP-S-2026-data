#include <bits/stdc++.h>
using namespace std;
long long n,cnt=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		int a;
		char b;
		cin>>a>>b;
		for(int i=0;i<a;i++){
			s+=b;
		}
	}
	long long len=s.size();
	long long l=0,r=len;
	for(int i=0;i<len/2+1;i++){
		if(s[l]!=s[r]) cnt++;
		l++,r--;
		//cout<<s[l]<<" "<<s[r]<<endl;
	cout<<cnt<<endl;
	return 0;
	}
}