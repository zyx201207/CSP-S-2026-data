#include<bits/stdc++.h>
#include<string>
using namespace std;
int n,a;
char c;
string s;
int minn(string s){
	int l=s.size()-1,cnt=0;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[l-i])cnt++; 
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>c;
		for(int j=1;j<=a;j++)s+=c;
	}
	cout<<minn(s);
	return 0;
}
