#include <bits/stdc++.h>
using namespace std;
long long a[5000010];
 int main(){
 	freopen("crystal.in","r",stdin);
 	freopen("crystal.out","w",stdout);
 	long long m,n,mout=0;
 	cin>>n>>m;
 	for(long long i=1;i<=n;i++){
 		cin>>a[i];
	 }
 	sort(a+1,a+n+1);
 	long long mid,x,max;
 	for(long long i=2;i<=n;i++){
 		mid=a[i];
 		x=0;
 		max=0;
 		for(long long j=i-1;j>=1;j--){ 
 			x+=mid-a[j];
 			if(x<=m){
 				max++;
 				if(mout<max)mout=max;
			 }else continue;
		 }
	 }
 	cout<<mout+1;
 	return 0;
 }
