#include<bits/stdc++.h>
using namespace std;
int n,m,a[300010],n2;
string s="n",s1;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	n2=n;
	while(n2--){
		s1="";
		int x=1;
		for(int i=n-n2+1;i<=n;i++){
			if(s1.find(s[i])) x=s1.find(s[i]);
			s1[x]=s[i];
			x++;
		}
		for(int i=1;i<x;i++) a[s1[i]-'0']++;
	}
	for(int i=1;i<=m;i++) cout<<a[i];
	return 0;
}
