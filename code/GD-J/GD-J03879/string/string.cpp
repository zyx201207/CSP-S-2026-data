#include <bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0;
	cin >>n;
	for(int i=0;i<n;i++){
		int k;
		char c;
		cin >>k>>c;
		for(int j=0;j<k;j++) s=s+c;
	}
	if(s.size()==1){
		cout <<0;
		return 0;
	}
	if(s.size()==2){
		if(s[0]!=s[1])cout <<1;
		else cout <<0;
		return 0;
	}
	if(s.size()%2!=0){
		string s1=s.substr(0,s.size()/2);
		string s2;
		for(int i=s.size()-1;i>=s.size()/2+1;i--)s2=s2+s[i];
		if(s1==s2){
			cout <<0;
			return 0;
		}
		for(int i=0;i<s.size()/2;i++){
			if(s1[i]!=s2[i]){
				s1[i]=s2[i];
				cnt++;
			}
		}
	}
	else{
		string s1=s.substr(0,s.size()/2);
		string s2;
		for(long long i=s.size()-1;i>=s.size()/2;i--)s2=s2+s[i];
		if(s1==s2){
			cout <<0;
			return 0;
		}
		for(int i=0;i<s.size()/2;i++){
			if(s1[i]!=s2[i]){
				s1[i]=s2[i];
				cnt++;
			}
		}
	}
	cout <<cnt;
	return 0;
}
