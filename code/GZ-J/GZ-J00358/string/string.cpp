//GZ-J00358 陈奕鸣
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans1=0,ans2=0;
	string s="";
	for(long long i=0;i<n;i++){
		long long l;
		char o;
		cin>>l>>o;
		for(long long i=0;i<l;i++){
			s=s+o;
		}
	}
	for(long long i=0;i<(s.size()+1)/2;i++){
		if(s[i]==s[s.size()-i]){
			ans1++;
		}
	}
	for(long long i=s.size();i>(s.size()+1)/2;i--){
		if(s[s.size()-i]==s[i]){
			ans2++;
		}
	}
	cout<<max(ans1,ans2);
	return 0;
}
