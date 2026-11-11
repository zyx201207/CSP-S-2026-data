#include <bits/stdc++.h>
using namespace std;
const int N=200005;
string s="0";
long long cs=0;
int n;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(long long j=1;j<=a[i];j++)s+=c[i];
	}
	long long len=s.length()-1;
	for(long long i=1;i<=len/2;i++){
		if(s[i]!=s[len+1-i])cs++;
	}
	cout<<cs;
	return 0;
}
//Trick||Treat!
