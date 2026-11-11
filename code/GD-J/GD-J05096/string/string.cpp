#include<bits/stdc++.h>
using namespace std;
long long n;
string s;
int fun(string s){
	long long sum=0;
	long long len=s.size();
	for(long long i=0;i<=len/2;i++){
		if(s[i]!=s[len-i-1]){
			sum++;
		}
	}
	return sum;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.in","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long x;
		char a;
		cin>>x>>a;
		while(x){
			s+=a;
			x--;
		}
	}
	cout<<fun(s);
	return 0;
}
