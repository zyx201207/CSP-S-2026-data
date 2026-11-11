#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ai[500005],mx=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
			cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			if(a[i]>a[j]){
				long long k=a[i];
				a[i]=a[j];
				a[j]=k;
			}
		}
	}
	for(long long i=1;i<n;i++){
		ai[i]=a[i+1]-a[i];
	}
	for(long long i=1;i<=n;i++){
		long long sum=0;
		long long j;
		for(j=i;j<=n;j++){
			if(sum+(j-i+1)*ai[j]>m){
				break;
			}else{
				sum+=(j-i+1)*ai[j];
			}
		}
		if(j-i>mx){
			mx=j-i+1;
		}
	}
	cout<<mx;
	return 0;
}
