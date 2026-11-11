#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,le=0;
	string s="";
	int a[200005]={};
	char c[200005]={};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		le+=a[i];
		for(int j=0;j<a[i];j++)s=s+c[i];
	}
	for(int i=0;i<(le/2);i++){
		if(s[i]!=s[le-(i+1)])cnt++;
	}
	cout<<cnt;
	return 0;
}
