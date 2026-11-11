#include<bits/stdc++.h>
using namespace std;
long long n;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		long long x;
		cin>>x;
		char c;
		cin>>c;
		for(long long i=0;i<x;i++){
			s+=c;
		}
	}
	long long cnt=0;
	for(long long i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j]){
			cnt++;
		}
	}
	cout<<cnt;
}
