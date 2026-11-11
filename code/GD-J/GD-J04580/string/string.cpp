#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s;
	cin>>n;
	for(int i=0;i<n;i++){
		int v;
		char va;
		cin>>v>>va;
		for(int i=0;i<v;i++){
			s+=va;
		}
	}
	int ans=0;
	int x=s.length();
	for(int i=x/2+1;i<x;i++){
		if(s[i]!=s[x-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
