#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[5000005],c=0,d[50000005]={1};
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	long long l=1,r=n;
	while(l<n&&r>l){
		long long u=m;
		long long mid=l/2+r/2;
		for(int i=mid;i>=1;i--){
			u-=a[mid]-a[i];
			if(u<0){
				break;
			}
			d[mid]++;
		}
		c=max(c,d[mid]);
		if(u>=0)l=mid+1;
		else r=mid;
	}

	cout<<c;
	return 0;
} 
