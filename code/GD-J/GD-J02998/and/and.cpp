#include<bits/stdc++.h>
#define long long 
using namespace std;

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
sort(a,a+n);
long long maxsum=0,x=0,y=0;
for(int j=n-1;j>=0;j--){
		for(int k=j-1;k>=0;k--){
			long long sum=a[j]&a[k];
			if(sum>maxsum)maxsum=sum,x=j,y=k;
			if(sum>=a[k-1])break;
	}
	}
	a[x]=0,a[y]=0;
	if(m==2){
	cout<<maxsum;
	return 0;
}
for(int i=0;i<m-2;i++){
long long sum=maxsum;
	maxsum=0;
	sort(a,a+n);
	for(int j=n-1;j>=0;j--){
		long long maxsum2=sum&a[j];
		if(maxsum2>maxsum)maxsum=maxsum2,x=j;
		if(maxsum2>=a[j-1])break;
	}
	a[x]=0;
}
cout<<maxsum;
	return 0;
}
