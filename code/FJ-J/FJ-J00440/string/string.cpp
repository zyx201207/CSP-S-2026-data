#include <bits/stdc++.h>
using namespace std;
const int N=200000;
long long n,a[N];
char c[30];
int main () {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	cin>>n;
	long long  sum=0;
	for(int i=0;i<n;i++) cin>>a[i]>>c[i];
	int j=n-1;
	for(int i=0;i<n/2;i++) {
		while(a[i]!=0) {
			if(c[i]!=c[j]) {
				sum+=min(a[i],a[j]);
				a[i]-=min(a[i],a[j]);	
				a[j]-=min(a[i],a[j]);
				if(j==0) j--;	
			} else break;
		}
	}
	cout<<sum;
	return 0;	
}
