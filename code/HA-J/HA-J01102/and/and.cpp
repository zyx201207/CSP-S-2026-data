#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long m,n,max=-1000000000;
	long long a[200010]= {};
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	int t=0,w=m-1,si=0;
	for(int i=0; i<n-1; i++) {
		for(int j=t; j<w; j++) {
			si=a[j]&a[j+1];
		}
		if(si>max) {
			max=si;
		}
		t++;
		w++;
	}
	cout<<max;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
