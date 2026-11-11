#include <bits/stdc++.h>
using namespace std;

int main() {
	freopen ("and.in","w",stdin);
	freopen ("and.out","r",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	int maxx[m]={-10},sum=0;
	for (int i=0;i<n;i++){
		for(int j=0;j<n;j++) {
			if (a[j]>maxx[i]) {
				maxx[i]	=a[i];
			}
		}
		for (int j=0; j<n; j++) if(maxx[i]==a[j]) a[j]=0;
	}
	long int t[10000000],g[10000000];
	for (int i=0; i<m; i++) {
		int j=0;
		while(maxx[i]>0) {
			if (i==0) {
				if (maxx[i]%2==1) {
					t[j]=1;
					maxx[i]/2;
					sum++;
				}
			} else {
				if (maxx[i]%2==1) {
					g[j]=1;
					maxx[i]/2;
				}
			}
			j++;
		}
		if (i==1) {
			for (int i=0; i<sum; i++) {
				if (t[i]!=g[i]) {
					t[i]=0;
				}
			}
		}
	}
	for (int i=0; i<sum; i++) {
		for (int j=0; j<=i; j++) {
			t[i]=t[i]*2;
		}
		sum+=t[i];
	}
	cout <<sum;
	return 0;
}

