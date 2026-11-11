#include<bits/stdc++.h>
using namespace std;	
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	int n,len=0;
	string s;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a>>b;
		while(a--
		){
			s[len++]='b';
		}
	}
	int cnt=0;
	for(int i=0,j=len;i<len,j>=0;i++,j--){
		if(s[i]==s[j])continue;
		cnt++;
	}
	cout<<cnt;
	return 0;
} 
