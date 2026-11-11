#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,c=1,cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char b;
		cin>>a;
		cin>>b;
		int p;
		for(int j=c;j<c+a;j++){
			s[j]=b;
			p=j+1;
		}
		c=p;
	}c=c-1;
	for(int i=1;2*i<=c;i++){
		if(s[i]!=s[c-i+1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
