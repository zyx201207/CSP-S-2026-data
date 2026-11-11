#include<bits/stdc++.h>
using namespace std;
char a[500000];
int b[500000];
long long c[300000];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			s+=a[j];
		}
	}
	for(int i=0; i<s.size(); i++) {
		for(int j=i+1; j<s.size(); j++) {
			if(a[i]==a[j]&&a[i]!='0') {
				for(int k=i; k<=j; k++) {
					a[k]=='0';
				}
			}
		}
	}
	for(int i=0; i<s.size(); i++) {
		b[i]=a[i]-'0';
	}
	for(int i=0; i<s.size(); i++) {
		if(b[i]!=0) {
			int q=b[i];
			c[q]++;
		}
	}
	for(int i=1; i<=m; i++) {
		cout<<c[i]<<" ";
	}
	return 0;
}
