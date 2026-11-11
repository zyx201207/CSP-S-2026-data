#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a,cnt=0;
char c;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s=" ";
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		} 
	}
	for(int i=1;i<=s.size()/2;i++){
		cnt+=(s[i]!=s[s.size()-i]);
	}
	cout<<cnt;
	return 0;
}
