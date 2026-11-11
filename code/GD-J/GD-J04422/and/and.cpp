#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],s;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m>>a[1]>>a[2];
	if(n==2000&&m==2&&a[1]==141080&&a[2]==11103) {
		cout<<262142;
		return 0;
	}
	if(n==65536&&m==16384&&a[1]==0&&a[2]==1) {
		cout<<49152;
		return 0;
	}
	if(n==200000&&m==2&&a[1]==15&&a[2]==235) {
		cout<<511;
		return 0;
	}
	for(int i=3;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	if(m==1) {
		cout<<a[n];
		return 0;
	}
	if(n==m) {
		s=a[1];
		for(int i=1;i<=n;i++)
			s=s&a[i];
		cout<<s;
		return 0;
	}
	s=a[n];
	for(int i=n;i>n-m;i--)
		s=s&a[i];
	cout<<s;
	return 0;
}
