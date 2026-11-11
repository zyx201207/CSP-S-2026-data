//王晨懿 GZ-S00422 贵阳市第一中学
#include<bits/stdc++.h>
using namespace std;
int find (long long m){
	long long l=1,r=2*1000000000;
	while(1){
		long long mid=(l+r)/2;
		if(mid%2==0){
			if((mid/2)*(mid+1)==m)return mid+1;
			if((mid/2)*(mid+1)>m&&(mid/2)*(mid+1)-mid<m)return m-(mid/2)*(mid+1)+mid;
			if((mid/2)*(mid+1)>m&&(mid/2)*(mid+1)-mid>m){
				r=mid-1; continue;
			}
			if((mid/2)*(mid+1)<m){
				l=mid+1; continue;
			}
		}
		if(mid%2==1){
			if(mid*((mid+1)/2)==m)return mid+1;
			if(mid*((mid+1)/2)>m&&mid*((mid+1)/2)-mid<m)return m-mid*((mid+1)/2)+mid;
			if(mid*((mid+1)/2)>m&&mid*((mid+1)/2)-mid>m){
				r=mid-1; continue;
			}
			if(mid*((mid+1)/2)<m){
				l=mid+1; continue;
			}
		}
	}
}
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a,b,c;
	cin>>n>>m;
	bool f=0,t=1;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a!=i)f=1;
		if(i>=3){
			if(b-a!=c-b)t=0;
		}
		c=b;
		b=a;
	}
	if(f==0){
		cout<<find(m);
		return 0;
	}
	if(t==1){
		m=m/(c-b);
		cout<<find(m);
		return 0;
	}
	return 0;
}
