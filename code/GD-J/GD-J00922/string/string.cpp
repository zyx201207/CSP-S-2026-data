#include<bits/stdc++.h>
using namespace std;
char awa[20000010];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long len=0;
	long long now=1;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		memset(awa+now,b,a);
		now+=a;
		len+=a;
	}
	string _,__;
	for(int i=1;i<=len/2;i++){
		_+=awa[i];
	}
	for(int i=len;i>=len-(len/2)+1;i--){
		__+=awa[i];
	}
	long long _1_=0;
	for(int i=0;i<len/2;i++){
		if(_[i]!=__[i])_1_++;
	}
	cout<<_1_;
	return 0;
}
