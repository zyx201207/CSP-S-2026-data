#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a,d,ans;
string t,s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>t;
		for(int j=1;j<=a;j++){
			s=s+t;
		}
		d=d+a;
	}	
	for(int i=0;i<d/2;i++){
		if(s[i]!=s[d-i-1])
		ans++;
	}
	cout<<ans;
	return 0;
}
/*
6 1000000000 a 1000000000 a 1000000000 a 1000000000 b 1000000000 b 1000000000 b
*/
