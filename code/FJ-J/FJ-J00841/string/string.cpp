#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,l=0;
	string st="";
	cin>>n;
	for(long long i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		l+=a;
		while(a--)st+=c;
	}//I hope computer can (1.5*1e9)/s.
	long long x,cnt=0;
	if(l%2==0)x=l/2-1;
	else x=l/2;
	for(long long i=0;i<=x;i++){
		if(st[i]!=st[l-i-1])cnt++;
	}
	cout<<cnt;
	return 0;
} 
