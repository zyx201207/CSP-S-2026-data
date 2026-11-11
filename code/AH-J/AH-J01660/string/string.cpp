#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	int len=s.size(),cnt=0;
	s=' '+s;
	for(int i=1;i<=ceil(len/2);i++){
		if(s[i]!=s[len-1+1]) cnt++;
	}
	cout<<cnt; 
	return 0;
}

