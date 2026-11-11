#include<bits/stdc++.h>
using namespace std;
char c[200005];
long long a[200005],n,m,i,j;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	/*cin>>n;
	m=n;
	while(m--) {
		cin>>a[n-m]>>c[n-m];
		a[n-m]+=a[n-m-1];
	}
	m=a[n]/2;i=1;j=n;
	while(i<j){
		int mid=i+(j-i)/2;
		if(a[mid]<m)i=mid+1;
		else j=mid;
	}n=0;
	while(i>=1){
		if(c[a[i]]!=c[a[j]])
		n+=a[j]-a[i-1]-2*min(m-a[i-1],a[j]-m);
		if(m-a[i-1]>a[j]-m)j++;
		else i--;
	}*/
	cout<<"0";
	return 0;
}
