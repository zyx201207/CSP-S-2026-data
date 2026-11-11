#include <bits/stdc++.h>
using namespace std;
int c,t;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--) {
		int ans=0;
		int n=0,m=0;
		int a[400]={0};
		cin>>n>>m;
	    for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		for(int i=1;i<=n;i++) {
			for(int k=i;k<=n;k++) {
				for(int j=i;j<=k;j++) {
					int sum=0;
				    sum+=a[j]-a[j-1];
					//cout<<sum<<" ";
					//cout<<endl;
					if(sum%m==0 && a[k]-a[i]>m) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5 
* 
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
