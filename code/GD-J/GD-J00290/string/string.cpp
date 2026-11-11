#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n,num,ans=0;
	char t;
	string s;
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>num>>t;
		for(long long j=0;j<num;j++){
			s+=t;
		}
	}
	int mid=s.size()/2;
	for(int i=0;i<mid;i++){
		if(s[i]!=s[s.size()-1-i]){
			ans+=1;
		}
	}
	cout<<ans;
	
return 0;}

