#include <bits/stdc++.h>
using namespace std;
int main(){
	//io
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	vector<char> s;
	vector<char> c;
	
	int n;
	cin>>n;
	
	long long amount;
	char tmp;
	
	for(int i=0;i<n;i++){
		cin>>amount;
		cin>>tmp;
		for(int j=0;j<amount;j++){
			s.push_back(tmp);	
		}	
	}
	
	int m=0;
	for(int i=0;i<(s.size()/2);i++){
		m+=int(s[i]);
	}
	if(((s.size()/2)*2)==s.size()){
		for(int i=s.size()/2;i<s.size();i++){
			m-=int(s[i]);
		}
	}
	else{
		for(int i=(s.size()/2+1);i<s.size();i++){
			m-=int(s[i]);
		}
	}
	
	
	if(m==0){
		cout<<0;
	}
	else{
		for(int i=0;i<(s.size()/2);i++){
			c.push_back(s[i]);
	}
	if(((s.size()/2)*2)==s.size()){
		for(int i=s.size()/2;i>0;i--){
			c.push_back(s[i]);
		}
	}
	else{
		c.push_back(s[s.size()/2+1]);
		for(int i=(s.size()/2-1);i>0;i--){
			c.push_back(s[i]);
		}
	}
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!=c[i]){
			cnt++;
	}
}
	cout<<cnt;
	}
}

