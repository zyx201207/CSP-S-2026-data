#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000000],b,d,h=1;
bool c[1000][100]={0},f,g[100000];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		b=a[i];
		d=0;
		while(b>0) {
			if(b%2==1)
				c[i][d]=1;
			d++;
			b/=2;
		}
	}
	for(int i=0;i<100;i++) {
		f=1;
		for(int j=1;j<n;j++) {
			if(c[j][i]!=c[j-1][i])
				f=0;
		}
		g[i]=f;
	}
	b=0;
	for(int i=0;i<100;i++) {
		for(int j=0;j<=i;j++) {
			h*=2;
		}
		b=h*g[i]+b;
	}
	cout<<b;
	return 0;
}
