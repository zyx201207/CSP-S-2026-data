#include<bits/stdc++.h>
using namespace std;
string str;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int ins;
		string inc;
		cin>>ins>>inc;
		for(int j=0;j<ins;j++){
			str+=inc;
		}
	}
	//cout<<str;
	int ji=0;
	for(int i=0;i<str.size()/2;i++) {
		if(str[i]!=str[str.size()-i-1]) {
			//cout<<i;
			ji++;
		}
		
	}
	cout<<ji;
	return 0;
} 
