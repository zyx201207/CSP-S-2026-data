#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],l,r,mid,zh[500005],maxn=-100000000;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(&a[1],&a[n+1]);
	zh[1]=a[1];
	for(int i=2;i<=n;i++) zh[i]=zh[i-1]+a[i];
	//
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1] && i<n){
			continue;
		}
		else{
			l=1;
			r=i;
			while(l<r){
				mid=(l+r)/2;
				if((i-mid+1)*a[i]-(zh[i]-zh[mid-1])<=m){
					maxn=max(maxn,i-mid+1);
					r=mid;
				}
				else{
					l=mid+1;
				}
			}
		}
	}
	cout<<maxn;
}
