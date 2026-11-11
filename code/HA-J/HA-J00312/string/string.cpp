#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		int t;char c;
		cin>>t>>c;
		for(int j=1;j<=t;j++){
			s+=c;
		}
	}
	string s1=s;
	reverse(s.begin(),s.end());
	if(s1==s){
		cout<<0;
		return 0;
	}
	ll res=0;
	for(int i=0;i<=s1.size()/2;i++){
		if(s[i]!=s[s1.size()-i-1]) res++;
	}
	cout<<res;
	return 0;
}

