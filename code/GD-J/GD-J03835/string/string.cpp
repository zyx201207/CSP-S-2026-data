#include<bits/stdc++.h>
using namespace std;
long long n,a[200010],q,l,m,bi;
char c,c1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	string s;
	cin>>n;
	cin>>a[1]>>c;
	for(int j=0;j<a[1];j++) s+=c;
	c1=c;
	for(int i=2;i<=n;i++){
		cin>>a[i]>>c;
		if(c1!=c) bi=1;
		for(int j=0;j<a[i];j++) s+=c;
	}
	if(bi==0){
		cout<<0;
		return 0;
	}
	l=s.size();
	if(l%2==1) m=l/2;
	else m=l/2-1;
	for(int i=0;i<=m;i++){
		if(s[i]!=s[l-i-1]) q++;
	}
	cout<<q;
	return 0;
}

