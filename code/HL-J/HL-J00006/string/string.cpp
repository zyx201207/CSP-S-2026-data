#include<bits/stdc++.h>
using namespace std;
vector<char> s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s1.push_back(c);
		} 
	}
	for(int i=0;i<s1.size()/2;i++){
		if(s1[i]!=s1[s1.size()-1-i]){
			s++;	
		}
			
	}
	cout<<s;
	return 0;
}
