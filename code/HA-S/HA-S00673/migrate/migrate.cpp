#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[2000005];
int fun(int n,int d) {
	int cnt=0;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		if(a[i]>0&&i+3<=n) {
			if(a[i+1]-a[i]<=d&&a[i+2]-a[i]<=d) {
				cnt++;
			}
		}
	}
	return cnt;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin>>c>>t;
	for(int i=1; i<=t; i++) {
		cin>>n>>d;
		for(int j=1; j<=n; j++) {
			a[j]=0;
		}
		cout<<fun(n,d)<<"\n";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
