#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m=0;
	cin>>n;
	string s;
	for(int i=0;i<n;i++){
		long long j;
		char c;
		cin>>j>>c;
		m+=j;
		string t(j,c);
		s+=t;
	}
	long long su=0;
	for(int i=0;i<m/2;i++){
		if(s[i]!=s[m-i]&&i!=m-i){
			su++;
		}
	}
	cout<<su;
	return 0;
} 
