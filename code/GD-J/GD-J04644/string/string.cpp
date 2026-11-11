#include<bits/stdc++.h>
using namespace std;
long long n,m=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		int x;
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	int x=s.size();
	for(int i=0;i<x/2;i++){
		if(s[i]!=s[x-i-1]){
			m++;
		}
	}
	cout<<m;
	return 0;
}
