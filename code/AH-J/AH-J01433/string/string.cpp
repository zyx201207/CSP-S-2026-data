#include<bits/stdc++.h>
using namespace std;
int top(int a){
	if(a/2!=0){
		return a/2+1;
	}
	return a/2;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,cnt=0;
	string s="";
	char c;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		for(int i=0;i<a;i++){
			s=s+c;
		}
	}
	n=s.size();
	for(int i=0;i<n/2;i++){
		for(int j=n-1;j>top(n);j--){
			if(s[i]!=s[j]){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
