#include<bits/stdc++.h>
using namespace std;
string s="";
long long cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		char ch;
		cin>>x>>ch;
		for(int j=0;j<x;j++){
			s+=ch;
		}
		cnt+=x;
	}
	long long l=cnt-1;
	long long ans=0;
	for(int i=0;i<cnt/2;i++){
		if(s[i]!=s[l-i]){
			ans++;
		}
	} 
	cout<<ans;
	return 0;
}
