#include <bits/stdc++.h>

using namespace std;

long long n,a,l,r;
long long ans;
string s,b,sq,sh;

int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>b;
		for(int i=1;i<=a;i++) s=s+b;
	}
	for(int i=0;i<(s.size()+1)/2;i++) sq=sq+s[i];
	l=s.size()-1;r=s.size()/2;
	for(int i=l;i>=r;i--) sh=sh+s[i];
	for(int i=0;i<sq.size();i++){
		if(sq[i]!=sh[i]) ans++;
	}
	cout<<ans;
	return 0;
}
