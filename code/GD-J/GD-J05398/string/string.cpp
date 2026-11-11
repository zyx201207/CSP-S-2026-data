#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,len,a[N];
char b[N];
string s=" ";
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		len+=a[i];
		while(a[i]--)s+=b[i];
	}
	int cnt=0;
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len-i+1])cnt++;
	}
	cout<<cnt;
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
