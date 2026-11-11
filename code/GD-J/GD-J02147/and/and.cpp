#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[200001],d[200001];
int nd(int x,int y) {
	string x1,y1;
	while(x) {
		if(x%2)x1+='1';
		else x1+='0';
		x/=2;
	}
	while(y) {
		if(y%2)y1+='1';
		else y1+='0';
		y/=2;
	}
	int b=0,mx=max(x1.size(),y1.size());
	for(int i=0; i<mx; i++) {
		if(x1[i]=='1' && y1[i]=='1') {
			int k=1;
			for(int j=0; j<i; j++)k*=2;
			b+=k;
		}
	}
	return b;
}
int main() {
	freopen("and","r",stdin);
	freopen("and","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			d[i]=nd(d[i-1],a[1]);
			if(i==j)continue;
			d[i]=max(d[i],nd(a[i],a[j]));
		}
	}
	cout<<d[m];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

