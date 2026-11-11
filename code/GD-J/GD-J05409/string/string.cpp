#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,m,cnt=0;
	char a;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>a;
		for(int j=1;j<=m;j++) s+=a;
	}long long len=s.length();
	for(int i=1;i<=len/2;i++){
	   if(s[i-1]!=s[len-i]) cnt++;
	}cout<<cnt;
	return 0;
}
