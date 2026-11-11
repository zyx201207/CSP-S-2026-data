#include<bits/stdc++.h>
using namespace std;
#define int long long
string x;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,an=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		int t;
		string s;
		cin>>t;
		cin>>s;
		for(int j=1;j<=t;j++)x+=s;
	}
	for(int i=0;i<x.size()/2;i++){
		if(x[i]!=x[x.size()-i-1])an++;
	} 
	cout<<an;
}
