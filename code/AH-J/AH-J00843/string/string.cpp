#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    string s="",s1="",s2="";
    long long n,cnt=0,f=0,x;
    cin>>n;
    char c;
    for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int i=0;i<x;i++){
			s=s+c;
		}
	}
	long long l=s.size()-1;
	for(int i=0;i<=l/2-1;i++){
		s1=s1+s[i];
	}
	for(int i=l;i>=l/2+1;i--){
		s2=s2+s[i];
	}
	for(int i=0;i<=l/2;i++){
		if(s1[i]!=s2[i]){
			cnt++;
		}
	}
	cout<<cnt;
    
    return 0;
}
