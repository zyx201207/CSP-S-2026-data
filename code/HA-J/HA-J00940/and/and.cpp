#include<bits/stdc++.h>
#define ll long long
using namespace std;
int sum[200005],a,b[200005],n,m,maxx=0,maxx2=0;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a;
		b[i]=a;
		maxx2=max(maxx2,a);
		if(i==1) {
			sum[i]=a;
		} else {
			sum[i]=sum[i-1]&b[i];
		}
	}
	
	if(m==2) {
		int i=1;
		while(i<=n-m+1) {
			int j=i+m-1;
			maxx=max(sum[j]-sum[i-1],maxx);
			i++;
		}
		int z=b[1]&b[n];
		maxx=max(maxx,z);
		cout<<maxx;
	}
	if(m==1) {
		cout<<maxx2;
	}
	if(m==n) {
		cout<<sum[n];
	}
	int maxx3=0;
	if(m==n-1) {
		for(int i=1; i<=n; i++) {
			int ans=0;
			for(int j=1; j<=n; j++) {
				if(i!=j) {
					ans=ans&b[j];
				}
			}
			maxx3=max(maxx3,ans);
		}
		cout<<maxx3;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
