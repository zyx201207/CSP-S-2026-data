#include<bits/stdc++.h>
using namespace std;
int x[10000000]= {4};
int y[10000000]= {3};
int ans[10000000];
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,u=0,max1=-1;
	cin>>n>>m;
	vector<long long>a(n);
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	for(int i=0; i<n-1; i++) {
		int j=i+1;
		int l=a[i],r=a[j];
		//fx
		for(int t=32; t>=0; t--) {
			if(a[i]>pow(2,t)) {
				a[i]-=pow(2,t);
				x[t]=1;
			} else if(l<pow(2,t)) {
				x[t]=4;
			} else {
				x[t]=0;
			}
		}
		//fy
		for(int t=32; t>=0; t--) {
			if(a[j]>pow(2,t)) {
				a[j]-=pow(2,t);
				y[t]=1;
			} else if(r<pow(2,t)) {
				y[t]=3;
			} else {
				t[y]=0;
			}
		}
		for(int p=32; p>0; p--) {
			cout<<x[p];
		}
		cout<<endl;
		for(int p=32; p>0; p--) {
			cout<<y[p];
		}
		cout<<endl;
		for(int p=32; p>0; p--) {
			if(x[p]==y[p]) {
				u++;
			}
		}
		if(u>max1) {
			max1=u;
		}
		u=0;
	}
	cout<<max1;
	return 0;
}
