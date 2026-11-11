#include<bits/stdc++.h>
using namespace std;
bool hw(string s){
	string s1="";
	for(int i=s.size()-1;i>0;i--){
		s1+=s[i];
	}
	if(s1==s)return 1;
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	string s;
	for(long long i=1;i<=n;i++){
		char c;
		int x;
		cin>>x>>c;
		for(long long j=1;j<=x;j++){
			s+=c;
		}
	}
	if(hw(s)){
		cout<<0;
		return 0;
	}
	long long cnt=0,mid=s.size()/2;
	mid+=s.size()%2;
	for(int i=0;i<mid;i++){
		if(s[i]!=s[s.size()-i-1]){
			cnt++;
			s[s.size()-i-1]=s[i];
		}
	}
	cout<<cnt;
    return 0;
}
