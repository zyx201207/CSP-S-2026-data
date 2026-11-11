#include<bits/stdc++.h>
using namespace std;
int n;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int l=1; l<=n; l++){
		int a;
		char c;
		cin>>a>>c;
		for(int l=1; l<=a; l++)s=s+c;
	}
	int cnt=0;
	for(int l=0; l<s.size()/2; l++){
		if(s[l]!=s[size()-1-l])cnt++;
	}
	cout<<cnt;
}
