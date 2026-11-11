#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+5];
	long long max1=-1,xb=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(max1<a[i]){
			max1=a[i];
			xb=i;
		}
	}
	a[xb]=-1;
	xb=0;
	long long sum=max1;
	for(int i=1;i<m;i++){
		max1=-1;
		for(int j=0;j<n;j++){
			if(max1<a[j]){
				max1=a[j];
				xb=j;
			}
		}
		a[xb]=-1;
		sum&=max1;
	}
	cout<<sum;
	return 0;
}
