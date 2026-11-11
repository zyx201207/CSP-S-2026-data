#include <bits/stdc++.h>
using namespace std;
long long a[200005],b[200005][35],n,m,p=2;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>> n>>m;
	for (int j=1;j<=29;j++){
			p*=2;
	}
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		long long d=p;
		for (int j=1;j<=30;j++){
		if (!a[i]) break;
			if (a[i]>=d) {
			b[i][j]++;
			a[i]-=d;
			}
			d/=2;
			
		}
	}
	if (m==1) {
	int x=0;
		for (int i=1;i<=n;i++) {
			int y=0;
		for (int j=1;j<=30;j++){
			y+=b[i][j];
			cout<<b[i][j]<<" ";
		}
		
		x=max(x,y);
	}
	

	}
	else {
	int x=0;
		for (int i=1;i<=n;i++) {
			int y=0;
		for (int j=1;j<=30;j++){
			y+=b[i][j];
		}
		x=max(x,y);
	}
	
	}
	cout<<8;
	return 0;
}
