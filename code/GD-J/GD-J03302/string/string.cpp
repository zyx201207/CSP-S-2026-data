//AC-Only_Small_Number
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int a;
	int c=0;
	cin>>a;
	for(int i=0;i<a;i++){
		int q;
		string w;
		cin>>q>>w;
		for(int j=0;j<q;j++){
			s+=w;
		}
	}
	//cout<<s<<endl;
	for(int i=0;i<s.length()/2;i++){
		if(s[i]!=s[s.length()-i-1]){
			c++;
		}
	}
	cout<<c;
	return 0;
} 
