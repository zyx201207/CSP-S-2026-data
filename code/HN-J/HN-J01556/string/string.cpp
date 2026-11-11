#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b,c=0;
	string s="",f;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>f;
		for(int j=0;j<a;j++)s+=f;
	}
	b=s.length()-1;
	for(int i=0;i<=b/2;i++){
		if(s[i]!=s[b-i])c++;
	}
	cout<<c;
	return 0;
} 
