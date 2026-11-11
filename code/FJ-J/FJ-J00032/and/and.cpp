#include<bits/stdc++.h>
using namespace std;
long long read() {
	long long x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		x=x*10+(c-'0');
		c=getchar();
	}
	return x*f;
}
long long n,m,k,x,a[200001],c[31],p[31];
bool b[200001][31];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	p[0]=1;
	for(int i=1;i<=30;i++)p[i]=p[i-1]*2;
	n=read(),m=read();
	for(int i=1; i<=n; i++) {
		x=read(),k=0;
		while(x) {
			if(x%2)b[i][k]=1,c[k]++;
			k++,x/=2;
		}
	}
	for(int i=0; i<=30; i++) {
		if(c[i]>=m) {
			for(int j=1; j<=n; j++) {
				if(b[j][i])a[j]+=p[i];
			}
		}
	}
	sort(a+1,a+n+1);
	k=p[30]*2-1;
	for(int i=n;i>n-m;i--){
		k&=a[i];
	}
	cout<<k;
	return 0;
}/*
5 3
31 3 1 7 15
*/
