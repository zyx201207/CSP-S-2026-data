#include<bits/stdc++.h>
using namespace std;
long long n,v,c,m;
char p;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>v>>p;
		for(int j=1;j<=v;j++) {
			m++;
			s+=p;
		}
	}
	for(int i=0;i<m/2;i++)
		if(s[i]!=s[m-i-1])
			c++;
	cout<<c;
	return 0;
}
