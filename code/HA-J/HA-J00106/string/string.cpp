#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	long long len_=0,cnt=0;
	string s=" ";
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		len_+=a;
		for(int j=0;j<a;j++){
			s+=c;
		}
		
	}
	for(long long i=1;i*2<=len_;i++){
		if(s[i]!=s[len_+1-i])cnt++;
	}
	cout<<cnt;
	return 0;
}


