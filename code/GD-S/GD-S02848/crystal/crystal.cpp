#include<bits/stdc++.h>
using namespace std;
int n,c,ans=0;
bool tsb=true;
long long m,sum=0,r,l;
long long a[1000000];
bool check(int nm){
	sum=0;
	for(int i=0;i<n;i++){
		if(a[i]<nm){
		sum+=nm-a[i];
		}
	}
	return sum<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==1)c=a[1]-a[0];
		if(i>1){
			if(a[i-a[i-1]]!=c)tsb=false;
			
		}
		
	}
	if(tsb==true){
		c=a[1]-a[0];
		long long tsans=(-c+sqrt(c*c+8*c*m))/2*c+1;
		cout<<tsans;
	}
	sort(a,a+n);
	l=a[0];
	r=a[n-1];
	while(l<r){
		int mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;

		}
		else{
			r=mid-1;
		}
	}

	for(int i=0;i<n;i++){
		if(a[i]<=l)ans++;
		else break;
	}
	cout<<ans;
	return 0;
}
