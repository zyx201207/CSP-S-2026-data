#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
bool pd(string s){
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1]){
			return false;
		}
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,x;
	char a;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>a;
		for(int i=1;i<=x;i++){
			s+=a;
		}
	}
	int cnt=0;
	if(pd(s)==true){
		cout<<0;
	}else{
		for(int i=0;i<s.size()/2;i++){
			if(s[i]!=s[s.size()-i-1]){
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
}

