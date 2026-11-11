#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;cin>>n;
	long long x;
	char c;
	string s;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int j=1;j<=x;j++)s+=c;
	}
	string s1;
	for(int i=s.size()-1;i>=0;i--){
		s1+=s[i];
	}
	long long k=0;
	for(int i=0;i<s.size();i++){
	    if(s[i]!=s1[i]){
	    	k++;
		}	
	}
	cout<<k/2;
	return 0;
}
