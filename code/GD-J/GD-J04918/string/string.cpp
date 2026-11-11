#include<bits/stdc++.h>
using namespace std;
long long n,l,he=0,ci=0;
char c;
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l>>c;
		he+=l;
		for(int j=1;j<=l;j++){
			s+=c;
		}
	}
	for(int i=0;i<=n/2;i++){
		ci+=(s[i]==s[he-1-i] ? 0 : 1);
	}
	cout<<ci;
	return 0;
} 
