#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k,cnt=0;
	cin>>n;
	char s1; 
	string s="";
	for(int i=1;i<=n;i++){
		cin>>k;
		cin>>s1;
		for(int j=1;j<=k;j++){
			s=s+s1;
		}
	}
	int f=1;
	for(int i=0;i<s.size()-1;i++){
		if(s[i]!=s[i+1]) f=0;
	}
	if(f==1) cout<<0;
	for(int i=(s.size()+1)/2;i<s.size();i++){
		if(s[i]!=s[s.size()-1-i]) cnt++;
	}
	cout<<cnt;
} 
