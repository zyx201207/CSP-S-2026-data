//GZ-J00656 黔西市思源实验学校 孙世嘉 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,c,m;
	int n;
	long long q=0;
	cin>>n;
	string g,og;
	for(int i=0;i<n;i++){
		cin>>m[i]>>c[i];
		
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m[i]-'0';j++){
			s.push_back(c[i]);
		}
	}
	if(s.size()%2!=0){
		for(int i=0;i<(s.size()-1)/2;i++){
			g.push_back(s[i]); 
		}
		for(int i=(s.size()-1)/2;(i>s.size()-1)/2;i--){
			og.push_back(s[i]); 
		}
		for(int i=0;i<g.size();i++){
			if(og[i]==g[i]){
				q++;
			}
		}
	}else{
		for(int i=0;i<s.size()/2;i++){
			g.push_back(s[i]);
		}
		for(int i=s.size();i>s.size()/2;i--){ 
			og.push_back(s[i]); 
		}
		for(int i=0;i<g.size();i++){
			if(og[i]!=g[i]){
				q++;
			}
		}
	}
	cout<<q;
	return 0;
} 
