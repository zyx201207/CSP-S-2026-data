#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000006],z[1000006];
int as;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++){
		z[i]=a[i];
		z[i]+=z[i-1];
	}
	for (int i=1;i<=n;i++){
		int l=1;
		int r=i;
		while(l<r){
			int mid=(l+r)/2;
			if (a[i]*(i-mid+1)-(z[i]-z[mid-1])<=m){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		as=max(as,i-l+1);
	}
	cout<<as;
	return 0;
}
// cant you cant you see me again
// let me 300+ ?