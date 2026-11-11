#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	int in1;
	char in2;
	while(n--){
		cin>>in1>>in2;
		while(in1--){
			s+=in2;
		}
	}
	string s1="",s2="";
	int l=s.size();
	for(int i=0;i<l;i++){
		if(i<=l/2){
			s1+=s[i];
		}
		else{
			s2+=s[i];
		}
	}
	reverse(s2.begin(),s2.end());
	int cnt=0;
	for(int i=0;i<l/2;i++){
		if(s1[i]!=s2[i]){
			cnt++;
		}
	}
	cout<<cnt; 
	return 0;
}
