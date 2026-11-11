#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e5+5;
int n;
int a[N],cnt,l;
char c[N];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	s=" "+s;
	for(int i=1;i<=s.size()/2;i++){
		if(s[i]!=s[l+1-i])cnt++;
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
1000000000 b*/
