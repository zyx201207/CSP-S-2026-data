#include<bits/stdc++.h>
using namespace std;
long long n,t,ans;
string s,a;
int huiwen(string x){
	for(long long i = 0;i<x.size();i++){
		if(x[i]==x[x.size()-1-i])
			continue;
		else
			return 0;
	}
	return 1;	 
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>t>>a;
		for(long long i = 1;i<=t;i++)
			s=s+a;
	}
	if(huiwen(s))
		cout<<0;
	else{
		for(long long i=0;i<s.size()/2;i++){
			if(s[i]==s[s.size()-1-i])
				continue;
			else{
				ans++;
			}
		}	
	}
	cout<<ans;
	return 0;
}

