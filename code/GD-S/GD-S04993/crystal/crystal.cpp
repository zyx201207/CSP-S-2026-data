#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000010],sum,q=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n%2!=0){
		q=n/2+1;
	}else{
		q=n/2; 
	}
	for(long long i=1;i<=n;i++){
		long long v=abs(a[q]-a[q+1-i]);
		if(m<abs(a[i]-a[q])){
			break;
		}
		if(i<=q){
			m-=v;
		}else{
			m-=(a[i]-a[q]);
		} 
		sum+=1;
	}
	cout<<sum;
	return 0;
}
