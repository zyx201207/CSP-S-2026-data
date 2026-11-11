#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int n;
	cin>>n;
	int num;
	char c;
	for(int i=1;i<=n;i++){
		cin>>num>>c;
		while(num--){
			s+=c;
		}
	}
	string x=s.substr(0,s.size()/2);
	string y=s.substr(s.size()/2);
	int cnt=0;
	for(int i=0;i<s.size()/2;i++){
		if(x[i]!=y[i])cnt++;
	}
	cout<<cnt;
	return 0;
	
	
} 
