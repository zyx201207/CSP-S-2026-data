#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],e;
int main(){
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout);
	cin>>n>>m;
	long long b;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		b+=a[i];
	}
	sort(a,a+n);
	long long c=b/n,d;
	if(c-a[n/2]<a[n/2+1]-c){
		d=a[n/2];
	} else{
		d=a[n/2+1];
	}
	for(int i=0;i<n;i++){
		if(a[i+d]-a[d]<a[d]-a[d-i]){
			if(m-a[d+i]+a[d]>0){
				e++;
				m=m-a[d+i]+a[d];
			}else{
				return 0;
			}
		}else{
			if(m-a[d]+a[d-i]>0){
				e++;
				m=m-a[d]+a[d-i];
			}else{
				return 0;
			}
		}
	}
	cout<<e;
	return 0;
}

