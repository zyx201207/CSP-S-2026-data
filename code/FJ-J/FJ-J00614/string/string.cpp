#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x,count=0;
	string s="";
	char a;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x>>a;
		for(long long j=1;j<=x;j++){
			s+=a;
		}
	}for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			count++;
		}
	}cout<<count;
	return 0;
}
