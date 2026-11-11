#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,c=0;
	string s;
	for(int i=0;i<n;i++){
		int a=0;
		string b;
		cin >>a>>b;
		for(int i=0;i<a;i++){
			b=s[i];
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]==s[i+1]){
			c++;
		}
	}
	if(c==s.size()){
		cout <<0;
	}
	return 0;
}
