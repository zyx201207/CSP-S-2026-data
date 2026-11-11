#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s="";
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(int j=0;j<a;j++)s+=c;
	}
	int mid=(s.size()-1)/2;
	long long cnt=0;
	for(int i=0;i<=mid;i++){
		if(s[i]!=s[s.size()-i-1])cnt++;
	}
	cout<<cnt;
	return 0;
}
