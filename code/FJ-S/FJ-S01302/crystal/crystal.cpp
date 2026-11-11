#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500100],i,j,ans,l,r,mid,num[500100]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(i=1;i<=n;i++){
		num[i]=num[i-1]+a[i];
	}
	l=1;
	r=n;
	while(l<r){
		mid=(l+r+1)>>1;
		if(a[mid]*mid<=m+num[mid]){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
