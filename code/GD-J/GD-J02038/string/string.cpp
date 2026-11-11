#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,c;
	cin>>n;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a;j++){
			cin>>a,c;
			s[i]=s.length()+1-i;
		}
	}
	cout<<s;
} 
