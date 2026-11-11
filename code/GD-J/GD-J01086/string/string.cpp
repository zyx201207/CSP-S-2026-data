#include<bits/stdc++.h>
using namespace std;


string __reverse(string s){
	string ans="";
	for(int i=s.size()-1;i>=0;i--){
		ans+=s[i];
	}
	return ans;
}
void adds(int x,char c,string &s){
	for(int i=0;i<x;i++){
		s+=c;
	}
	return;
}
string fronts(string s){
	int sze=s.size()/2;
	string ans="";
	for(int i=0;i<sze;i++){
		ans+=s[i];
	}
	return ans;
}
string rears(string s){
	int sze=s.size()/2+1;
	if(s.size()%2==1)sze+=1;
	string ans="";
	int siz=s.size();
	for(int i=sze-1;i<siz;i++){
		ans+=s[i];
	}
	return ans;
}
int cntdiff(string s1,string s2){
	int ans=0;
	
	for(int i=0;i<s1.size();i++){
		if(s1[i]!=s2[i])ans++;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//main 
	int ans=0,n;
	string s="";
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		adds(a,c,s);
	}
	string s1=fronts(s);
	string s2=__reverse(rears(s));
	ans=cntdiff(s1,s2);
	cout<<ans;
	return 0;
}

