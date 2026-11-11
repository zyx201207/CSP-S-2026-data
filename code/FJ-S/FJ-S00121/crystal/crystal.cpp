#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ma=0;
long long check(long long h){
	long long sum=0,mm=m;
	for(long long i=n;i>=1;i--){
		if(a[i]>h){
			continue;
		}else if(a[i]==h){
			sum++;
		}else{
			long long hh=h-a[i];
			if(mm<hh){
				break;
			}else{
				sum++;
				mm-=hh;
			}
		}
	}
	if(sum>=ma){
		return sum;
	}
	return 0;
}
void ppcs(long long h){
	long long sum=0,mm=m;
	for(long long i=n;i>=1;i--){
		if(a[i]>h){
			continue;
		}else if(a[i]==h){
			sum++;
		}else{
			long long hh=h-a[i];
			if(mm<hh){
				break;
			}else{
				sum++;
				mm-=hh;
			}
		}
	}
	cout<<sum;
	return ;
}
int main(){ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long l=a[1],r=a[n],mid;
	while(l<r){
		mid=(l+r+1)/2;
		long long c=check(mid);
		if(c>ma){
			ma=c;
			r=mid;
		}else{
			l=mid;
		}
	}
	ppcs(l);
	return 0;
} 
