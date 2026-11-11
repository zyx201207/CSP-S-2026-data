#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in",'l',stdin);
	freopen("crystal.out",'r',stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(long long i=0;i<n;++i)cin>>a[i];
	sort(a,a+n);
	for(long long i=0;i<n-1;++i){
		if(a[i]<a[i+1]){
			if(i==0){
				if(m>=a[i+1]-a[i]){
					m=m-a[i+1]+a[i];
					a[i]=a[i+1];
				}else{
					cout<<1;
					return 0;
				}
			}else{
				if(m>=(a[i+1]-a[i])*(i+1)){
					m=m-(a[i+1]-a[i])*(i+1);
					for(long long j=0;j<=i;++j){
						a[j]=a[i+1];
					}
				}else{
					cout<<i+1;
					return 0;
				}
			}
		}
	}cout<<n;
	fclose("crystal.in");
	fclose("crystal.out");
}
