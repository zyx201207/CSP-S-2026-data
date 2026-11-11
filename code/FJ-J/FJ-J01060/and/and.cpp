#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,cnt=0;
	cin>>n>>m;
	long long a[n],b[m];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<m;i++){
		b[i]=a[n-1-i];
	}
	cnt=b[0];
	for(int i=1;i<m;i++){
		cnt=cnt&b[i];
	}
	cout<<cnt;
	return 0;
}
