#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,x,ans,anss;
string s;
char v;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>v;
		for(int j=x;j<x+a;j++) 
			s[j]=v;
		x+=a;
	}
	for(int i=0;i<x/2;i++){
		if(s[i]!=s[x-1-i]) ans++;
	}
	cout<<ans;
	
	return 0;
} 
