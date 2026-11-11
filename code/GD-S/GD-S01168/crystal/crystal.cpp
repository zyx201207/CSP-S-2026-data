#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100001],t=1,sum=0,cnt=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>> n >> m;
	for(int i=1;i<=n;i++){
		cin>> a[i];
		sum+=a[i];
	}
	sum/=n;
	if(n==1){
		cout<< 1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(m<=0){
			break;
		}
	    if(a[i]<sum){
	    	a[i]=sum;
	    	m-=sum-a[i];
		}
		if(a[i]>sum){
			continue;
		}
		cnt++;
	}
	cout<< cnt;
	return 0;
} 
