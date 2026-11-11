#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0;
string s;
int main(){
	freopen("string.in","w",stdin);
	freopen("string.out","r",stdout);
	cin>>n;
	for(int j=1;j<=n;j++){
		long long a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	long long len=s.size();
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-1-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
