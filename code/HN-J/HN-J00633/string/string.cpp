#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n;
string s;
long long ans=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	s+=" ";
	rep(i,1,n){
		int x;
		char ch;
		cin>>x>>ch;
		rep(j,1,x)
			s+=ch;
	}
	int l=s.size()-1;
	rep(i,1,l>>1){
		if(s[i]!=s[l+1-i])
			ans++;
	}
	cout<<ans;
	return 0;
}
