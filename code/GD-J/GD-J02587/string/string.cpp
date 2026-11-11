#include<bits/stdc++.h>
using namespace std;
long long n,x,m = 0,t = 0;
char y;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n;
	for(int i = 0;i<n;i++){
		cin>>x>>y;
		for(int j = 0;j<x;j++){
			s+=y;
		}
		m+=x;
	} 
	for(int i = 0;i<m/2;i++){
		if(s[i]!=s[m-1-i]) t++;
	}
	cout<<t;

	return 0;
} 
 
