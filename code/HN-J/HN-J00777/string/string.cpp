#include<bits/stdc++.h>
using namespace std;
string s;
char c;
long long n,l,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		cin>>c;
		for(int i=0;i<x;i++){
			s+=c;
		}
	}
	l=s.size();
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i-1]){
			s[l-i-1]=s[i];
			ans++;	
		}
	}
	cout<<ans;
	return 0;
}

