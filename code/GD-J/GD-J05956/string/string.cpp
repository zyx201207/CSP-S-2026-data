#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0;
	cin>>n;
	string s,s1;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i]>>s1;
		for(int j=0;j<a[i];j++){
			s+=s1;
		}
	}
	if(s.size()%2==0){
		for(int i=0;i<s.size();i+=2){
			if(s[i]!=s[s.size()-i-1]){
				cnt++;
			}
		}
	}else{
		for(int i=0;i<s.size()-1;i+=2){
			if(s[i]!=s[s.size()-i-1]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
