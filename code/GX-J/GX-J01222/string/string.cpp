#include <cstdio>
#include <bits/stdc++.h>
	
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,num,l,c;
	num=0;
	l=0;
	cin>>n;
	string s,a;
	for(long long i=1;i<=n;i++){
		cin>>c;
		cin>>a;
		l+=c;
		while(c--)s+=a;
	}
	for(long long i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
			num++;
		}
	}
	cout<<num;
	return 0;
}
