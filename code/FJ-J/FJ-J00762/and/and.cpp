#include <bits/stdc++.h>
using namespace std;
long long a[200005];
bool isx(long long x,long long count){
	long long t=2;
	for(int i=0;i<30;++i){
		if(x==t-count){
			return 1;
		}
		t*=2;
	}
	return 0;
}
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,sum=0,msum=0;
	int dyc=1;
	cin>>n>>m;
	for(long long i=0;i<n;++i){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	long long count=1;
	while(1){
		for(long long i=0;i<n;i++){
			if(isx(a[i],count)){
				if(dyc){
					sum+=a[i];
					dyc=0;
					msum++;
				}
				else{
					sum&=a[i];
					msum++;
				}
			}
			if(msum==m){
				cout<<sum;
				return 0;
			}
		}
		count++;
	}
	return 0;
}
