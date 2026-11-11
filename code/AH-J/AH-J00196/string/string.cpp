#include<bits/stdc++.h>
using namespace std;
string s="0";
int n,x,c;
char y;
int main(){
	cin>>n;
	while(n--){
		cin>>x>>y;
		for(int i=1;i<=x;i++) s=s+y;
	}
	x=s.size();
	for(int i=1;i<=x/2;i++){
		if(s[i]!=s[n-i+1]) c++;
	}
	cout<<c;	
	return 0;
}
