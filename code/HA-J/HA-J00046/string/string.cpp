#include<bits/stdc++.h>
using namespace std;
int n,num,ans,m;
int l=1,r,x=1;
int a[200010];
char c[200010];
char b[2000010];
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	m=1;
	for(int i=1; i<=n; i++) {
		cin>>a[i]>>c[i];
		num+=a[i];
		if(c[i]!=c[i-1]&&i>1) {
			m=0;
		}
	}
	if(m==1) {
		cout<<0;
		return 0;
	}
	r=num;
	if(num>2000010)return 0;
	int x=1;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=a[i]; j++) {
			b[x]=c[i];
			x++;
		}
	}
	for(int i=1; i<=num/2; i++) {
		if(b[i]!=b[num+1-i]) {
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
