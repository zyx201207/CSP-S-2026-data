#include<bits/stdc++.h>
using namespace std;
string s="";
char c;
int n,a;
long long fix(string s){
	string str="";
	for(int i=s.size()-1;i>=0;i--) str.push_back(s[i]);
	if(s==str) return 0;
	long long n=0;
	for(int i=0;i<=s.size()/2;i++) if(s[i]!=str[i]) n++;
	return n;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++) s.push_back(c);
	}
	cout<<fix(s);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
