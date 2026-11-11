#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,a[500001],max=0,sum;
	long long m;
	cin>>n>>m;
	int c[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=1;i<=n-1;i++){
		c[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i;j<=n;j++){
			for(int l=i;l<=j;l++){
				sum+=c[l];
				if(sum>m){
					break;
				}
				if(max<j-i+2){
					max=j-i+2;
				}
			}
		}
	}
	cout<<max;
	return 0;
}
