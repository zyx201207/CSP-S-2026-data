#include<bits/stdc++.h>
using namespace std;
int n,m;
long long mx;
int a[500000];
int main () { 
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int mi=0;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		mi=max(mi,a[i]);
	}
	if (m==1) {
		cout<<mi<<endl;
	}
	for (int i=1;i<=n;i++) {
		
		for (int j=i;j<=n;j++) {	
			int l=1;
			long long ans=a[i];
			while (l<m) {
				ans=ans&a[l+j];
				l++;
			} 
			mx=max(ans,mx);
		}
		
	}
	cout<<mx<<endl;
	return 0;
}
 
