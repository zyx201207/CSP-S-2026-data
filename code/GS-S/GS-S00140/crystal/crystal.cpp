#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	long long a[555555555];
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=0;i<n;i++){
		long long o=i;
		for(long long j=n;j>1;j--){
			if(i+j>n) continue;
			long long k=m;
			long long dd=j,nn=j;
			while(nn--){
				k-=a[i+dd-1]-a[o];
				o++;
			}
			if(k>=0){
				cout<<j;
				return 0;
			}
		}
	}
	return 0;
}
