#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,x,ans;
string y,s,s1;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> x >> y;
		for(int j=1;j<=x;j++)
			s += y;
	}
	int len = s.size();
	for(int i=0;i<len;i++){
		s1[i]=s[len-1-i];
	}
	int c = len / 2;
	for(int i=0;i<c;i++){
		if(s[i]!=s1[i])
			ans++;
	}
	cout << ans;
	return 0;
}
/*
s  a a a b b b
len = 6 
s1 
   0 1 2 3 4 5 6 7 8 9
*/
