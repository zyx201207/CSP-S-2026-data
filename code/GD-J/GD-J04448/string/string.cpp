#include<bits/stdc++.h>
using namespace std;
long long n,x,l=0,ans=0;
string s,x1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>x1;
		l+=x;
		for(int j=0;j<x;j++){
			s+=x1;
		}
	}
	for(int i=0;i<l;i++){
		if(s[i]!=s[l-1-i]){
			ans++;
			s[i]=s[l-i-1];
		}
	}
	cout<<ans;
	return 0;
}
