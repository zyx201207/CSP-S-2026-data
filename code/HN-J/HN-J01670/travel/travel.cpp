#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=101;

int a,b;
char s[N],t[N];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>t;
	if(a==b)
		cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(s[0]==t[0]&&s[1]==t[1])
		cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;
	}
	if((s[2]<='C'&&t[2]<='C')||(s[2]>='D'&&t[2]>='D'))
		cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if(abs(s[2]-t[2])==1)
		cout<<1;
	else
		cout<<0;
}
