#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,j=0;
	cin>>n;
	for(int i=0;i<n;i++){
		int a,k;
		char b;
		cin>>a>>b;
		for(k=j;k<a+j;k++){
			s[j]=b;
		}
		j=k;
	}if(n<=1){
		cout<<0;
		return 0;
	} 
	int a=s.size(),ans=0;
	for(int i=0;i<a/2;i++){
		if(s[i]!=s[a-i]){
			ans++;
		}
	}cout<<ans;
	return 0;
}
