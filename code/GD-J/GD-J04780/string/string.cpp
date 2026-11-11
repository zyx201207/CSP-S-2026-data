#include <bits/stdc++.h>
using namespace std;
int sring(string s){
	int l=0,r=s.size();
	int tmp=0;
	for(int i=1;i<=s.size()/2;i++){
		if(s[l]!=s[r]){
			tmp++;
		}
		l++;
		r--;
	}
	return tmp;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	int a;
	char c;
	cin>>n;
	int tmp=0;
	for(int i=1;i<=n;i++){

		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
		}
	}
	cout<<sring(s);
	return 0;
}
