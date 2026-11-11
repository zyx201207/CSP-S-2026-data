#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,len=0;string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		int m;char c;
		cin>>m>>c;
		len+=m;
		while(m--){
			s+=c;
		}
	}
	long long ans=0;
	for(int i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1])ans++;
	}
	cout<<ans;
	return 0;
} 
