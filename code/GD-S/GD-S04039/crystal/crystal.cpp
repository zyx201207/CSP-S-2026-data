#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	long long n,m,max=-1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long c=m;
	for(long long i=1;i<=n;i++){
		long long cnt=a[i];
		m=c;
		long long sum=0;
		for(long long j=1;j<=n;j++){
			if(a[j]<cnt&&(cnt-a[j])<m){
				m=m-(cnt-a[j]);
				a[j]=cnt;
			}
		}
		for(long long j=1;j<=n;j++){
			if(a[j]==cnt){
				sum++;
			}
		}
		if(sum>max){
			max=sum;
		}
	}
	cout<<max;
	return 0;
}
