#include<bits/stdc++.h>
using namespace std;
long long n,len,cnt,cnt1;
string s=" ",s1=" ";

int main(){
	cin>>n;
	while(n--){
		int x;
		char a;
		cin>>x>>a;
		len+=x;
		for(int i=1;i<=x;i++){
			s+=a;
		}
	}
	for(int i=1;i<=len;i++){
		s1+=s[len-i+1];
	}
	for(int i=1;i<=(len+1)/2;i++){
		if(s[i]!=s1[i]) cnt++;
	}
	for(int i=(len+1)/2;i<=len;i++){
		if(s[i]!=s1[i]) cnt1++;
	}
	cout<<min(cnt,cnt1);
	return 0;
}
