#include<bits/stdc++.h>
using namespace std;
long long a[1000001],b[1000001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long j=0;j<n;j++){
		long long t=j,m1=m,r=1;
		for(long long i=0;i<n;i++){
			if(((a[n-2-t-i]+m1)>=a[n-t-1])&&((n-2-t-i)>=0)){
				r++;
				m1=m1-(a[n-t-1]-a[n-2-t-i]);
			}
			if(((a[n-2-t-i]+m1)<a[n-t-1])||((n-2-t-i)<0)){
				break;
			}
		}
		b[j]=r;
		
	}
	sort(b,b+n);
	cout<<b[n-1];
	return 0;
}
