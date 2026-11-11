#include<bits/stdc++.h>
using namespace std;
const int N=1e7+10;
long long a[N];
long long sum=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
	} else if(m==2){
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				if((a[i]&a[j])>sum) sum=(a[i]&a[j]);
			}
		}
		cout<<sum;
	} else if(m==3){
		for(long long i=1;i<=n;i++){
			for(long long j=i+1;j<=n;j++){
				for(long long k=j+1;k<=n;k++){
					if((a[i]&a[j]&a[k])>sum) sum=(a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<sum;
	} else if(m==n){
		for(long long i=1;i<=n;i++){
			sum&=a[i];
		}
	} else{//A,B
		sort(a+1,a+1+n);
		cout<<a[n];
	}
	return 0;
}
