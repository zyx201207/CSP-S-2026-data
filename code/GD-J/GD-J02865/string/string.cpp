#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	
	long long n, a;
	string c, text="";
	cin>>n;
	for(int i=0; i<n; i++){
		cin>>a;
		cin>>c;
		for(int j=0; j<a; j++){

			text+=c;
		}
	}
	string com;
		com="";
		int z = text.size()%2==0 ? 0:1;
		int size = text.size()/2 + z;
		for(int j=size- 1-z; j>=0; j--){
			com+=text[j];
		}
		int max_=0;
		for(int j=size; j<text.size(); j++){
			if(text[j]!=com[j-size])max_++;
		}
	cout<<max_;
	
	return 0;
} 
