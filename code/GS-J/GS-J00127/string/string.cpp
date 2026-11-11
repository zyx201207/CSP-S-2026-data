#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int n;
	int cnt=0;
	cin>>n;
	while(n--){
		int a;
		cin>>a;
		char c;cin>>c;
		while(a--)s+=c;
	}
	int len=s.size();
	
	string s1=s.substr(0,len/2);
	string s2=s.substr(len/2+1,len/2);
	reverse(s2.begin(),s2.end());
	for(int i=0;i<=len/2-1;i++){
		if(s1[i]!=s2[i])cnt++;
	}
	cout<<cnt;
	
	
	return 0;
}
