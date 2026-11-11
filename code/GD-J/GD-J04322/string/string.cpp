#include<bits/stdc++.h>
using namespace std;
long long l[27];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,x,c=0,t=0;char y;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		if(l[y-'a']==0)c++;
		l[y-'a']+=x;
		t+=x;
	}
	if(c==1)cout<<0;
	else cout<<t/c;
	return 0;
}
