#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n];
	for(long long x=0;x<n;x++)cin>>a[x];
	long long count=0,count_m=0,count_n=1;
	for(long long c=0;c<n;c++){
		for(long long d=0;d<n;d++){
			if(a[d]>a[d+1]){
				long long temp=a[d];
				a[d]=a[d+1];
				a[d+1]=temp;
			}
		}
	}
	for(long long sum=1;sum<=n;sum++){
	    for(long long y=0;y<=n;y++){
	    	count_m=0;
	    	for(long long y_temp=0;y_temp<=(y+sum);y_temp++){
	    		if(a[y]==a[y+sum])break;
	    		a[y]++;
	    		count_m++;
			}
			count=count+count_m;
			if(count <= m)count_n++;
		}
	}
	cout<<count_n;
	return 0;//5 8 -3 -1 2 2 7
} 
