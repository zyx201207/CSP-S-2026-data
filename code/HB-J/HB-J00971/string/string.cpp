#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	int n;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		long long l;
		string z;
		cin>>l>>z;
		for(int j=1;j<=l;j++){
			s=s+z;
		}
	}
	string a="",b="";
	int len=s.size();
	for(int i=0;i<len/2;i++){
		a=a+s[i];
	}
	if(s.size()%2==0){
		for(int i=len/2;i<len;i++){
			b=b+s[i];
		}
	}
	else{
		for(int i=len/2+1;i<len;i++){
			b=b+s[i];
		}
	}
	long long num=0;
	for(int i=0;i<len/2;i++){
		if(a[i]!=b[i]){
			num++;
		}
	}
	cout<<num;
	return 0;
}

