#include<bits/stdc++.h>
using namespace std;
int n;
long long a[200005];
char c[1];
string s;
long long sum;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int k=0;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++) {
			k++;
			s[k]=c[i];
		}
	}
	for(int i=1;i<=k;i++) {
		if(s[i-1]==s[k]+1-i) sum++;
	}
	cout<<sum;
	return 0;
}
