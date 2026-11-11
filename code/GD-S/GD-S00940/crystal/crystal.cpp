#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],b[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		int k=0,s=0;
		bool f=1;
		for(int i=1;i<=n-mid+1;i++){
			k=mid*a[i+mid-1];
			s=b[i+mid-1]-b[i-1];
			if(k-s<=m){
				l=mid+1;
				f=0;
				break;
			}
		}
		if(f)r=mid-1;
	}
	cout<<r;
}
