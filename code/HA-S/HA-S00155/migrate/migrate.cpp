#include <bits/stdc++.h>
#include <cstdio>
#define intn long long
using namespace std;
intn c,t,n,d,x[2000005],ans;
intn l(intn f,intn s) {
	return ((x[s]-x[f])+d-1)/d;
}
int main() {
		freopen("migrate.in","r",stdin);
		freopen("migrate.out","w",stdout);
	cin>>n>>t;
	for(int i=1; i<=t; i++) {
		ans=0;
		cin>>n>>d;
		//
		//
		for(int i=1; i<=n; i++) {
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			if(x[i]-x[i-1]>d){
				n=i-1;
				break;
			}
		}
		for(int i=1; i<=n; i++) {
			for(int j=i+3; j<=n; j++) {
				if((l(i,j)*d-1)==x[j]-x[i]) ans++;
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
