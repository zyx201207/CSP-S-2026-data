#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,z,i,j,k,a[500005],b[300005],c,d;
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(i=1; i<=n; i++) {
		string s;
		for(j=i; j<=n; j++) {
			x=s.find(char(a[j]-'0'));
			if(x!=-1) {
				s.erase(x,(n-x));
			}
			s=s+char(a[j]-'0');
		}
		for(j=0; j<s.size(); j++) {
			b[int(s[j]-'0')]++;
		}
	}
	for(i=1; i<=m; i++) {
		cout<<b[i]<<" ";
	}
	return 0;
}
/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
