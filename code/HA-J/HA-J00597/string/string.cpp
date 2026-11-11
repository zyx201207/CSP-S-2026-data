#include<bits/stdc++.h>
using namespace std;
long long n,c;string s;char x;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++){
		int d;cin>>d>>x;
		for(int j=1;j<=d;j++) s+=x;
	}
	long long len=s.size();
	for(long long i=0;i<len/2;i++){
		if(s[i]!=s[len-i-1]) c++;
	}
	cout<<c;
	return 0;
}

