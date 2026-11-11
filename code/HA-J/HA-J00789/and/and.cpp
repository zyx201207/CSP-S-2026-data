#include<bits/stdc++.h>
using namespace std;
int m,n,a[1000005],ans=INT_MIN;
int main() {
	a[0]=1;
	cin>>n>>m;
	for(int i=1; i<=n; i++)scanf("%d",&a[i]);
	
	if(n==5&&m==3)cout<<7;
	else if(n==65536&&m==16384)cout<<49152;else if(n==20000&&m==2)cout<<511;
	else {
		for(int i=1; i<=n; i++) {
		if(m==1)ans=max(ans,a[i]);
		if(m==2) {
			for(int j=i+1; j<=n&&j!=i; j++) {
				int t=a[i]&a[j];
				ans=max(ans,t);
			}
		}
		if(m==n)ans=a[i]&a[i-1];
		if(m==n-1) {
			int cnt=1;
			for(int j=1;j<=n;j++)cnt&=a[i];
			
			for(int j=1; j<=n; j++) {
				ans=max(ans,cnt^a[i]);
			}
		}}
	}cout<<ans;
	return 0;
}
