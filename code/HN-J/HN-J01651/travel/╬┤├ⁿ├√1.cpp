#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y,n,m;
	char s,r;
	cin>>x>>n>>s>>y>>m>>r;
	cout<<x<<" "<<n<<" "<<s<<" "<<y<<" "<<m<<" "<<r<<" ";
	if(x==y)cout<<1;
	else cout<<0;
	if(n==m)cout<<1;
	else cout<<0;
	if(s=='C'&&r=='D')cout<<0;
	else if(s>='A'&&s<='C'&&r>='A'&&r<='C')cout<<1;
	else if(s>='D'&&s<='F'&&r>='D'&&r<='F')cout<<1;
	else cout<<0;
	if(s=='C'&&r=='D')cout<<0;
	else if((s+1)==r)cout<<1;
	else cout<<0;
	return 0;
}  
