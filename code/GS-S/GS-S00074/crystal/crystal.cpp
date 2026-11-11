#include<bits/stdc++.h>
using namespace std;
int n,a[500005],sum=1,b[500005];
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	while(1){
	int l=a[1],r=a[n];
		while(l<r){
		int mid=l+r+1>>1;
		if(a[mid]*mid==b[mid]-b[l-1]+m){
			cout<<mid;
			return 0;
		}
		if(a[mid]*mid>b[mid]-b[l-1]+m)r=mid-1;
		else l=mid+1;
		}
		m--;
	}
	return 0;
} 



