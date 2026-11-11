#include<bits/stdc++.h>
using namespace std;
string s=" ";
#define int long long
int a;
int n;
char c;
int cnt;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--)s+=c;
	}
	int r=1,l=s.size()-1;
	while(r<=l){
		if(s[r]!=s[l])cnt++;
		r++;
		l--;
	}
	cout<<cnt;
	return 0;
}
