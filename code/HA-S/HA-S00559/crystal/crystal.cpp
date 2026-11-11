#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100000005],b[100000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long cnt=0;
	for(long i=1;i<=n;i++){
		if(a[i]>a[i+1]){
			cnt=a[i];
			a[i]=a[i+1];
			a[i+1]=cnt;
		}
	}
	long long a1=0;
	long long x1=n/2;
	if(n%2==1){
		for(long long i=n;i>=1;i--){
			if(a[i+1]==a[x1+1]){
				cout<<i+1<<endl;
				break;
			}
		}
	}
	else{
		for(long long i=n;i>=1;i--){
			if(a[i]==a[x1]){
				cout<<i;
				break;
			}
		}
	}
	return 0;
} 
