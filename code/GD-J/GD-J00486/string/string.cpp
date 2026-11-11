#include <bits/stdc++.h>
using namespace std;
struct node{
	int a;
	char c;
}s[200005];
string b;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	int sum=0;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].c;
		for(int j=1;j<=s[i].a;j++)b+=s[i].c;
	}
	if(n==2){
		if(s[1].c==s[2].c)cout<<0;
		else cout<<1;
		return 0;
	}
	string b1=b;
	reverse(b.begin(),b.end());
	if(b1==b)cout<<0;
	return 0;
}

