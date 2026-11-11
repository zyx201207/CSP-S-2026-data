#include<bits/stdc++.h>
using namespace std;
string s;int num;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int a;char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}  
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i-1])num++;
	}cout<<num;
	return 0;
}


