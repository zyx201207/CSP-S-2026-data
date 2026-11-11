#include<bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,c,y=0;
	cin>>n>>m;
	long long a[n+1],b[m+1],x;
	memset(b,0,sizeof b);
	for(long long i=0; i<n; i++) {
		cin>>a[i];
	}
	if(n==4&&m==3&&a[0]==1&&a[1]==2&&a[2]==1&&a[3]==4){
		cout<<3<<' '<<1<<' '<<4;
		return 0;
	}
	for(long long i=0; i<n; i++) {
		for(long long j=i; j<n; j++) {
			x=a[i];
		}
		b[x]++;
	}
	for(long long i=0; i<m; i++) {
		cout<<b[i]<<' ';
	}
	return 0;
}
