#include <bits/stdc++.h>
using namespace std;
long long c[500005];
long long d[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,i,j,a,b,x,y,max1=0;
	cin>>n>>m;
	for(i=0;i<n;i++){
		cin>>c[i];
		for(j=i;j>0;j--){
			if(c[j]<c[j-1]){
				a=c[j];
				c[j]=c[j-1];
				c[j-1]=a;
			}
		}
	}
	
	for(i=n-1;i>0;i--){
		b=m;
		for(j=i-1;j>=0;j--){
			x=c[i]-c[j];
			if(x>b){
				y=j;
				break;
			}
			if(j==0)
				y=j-1;
			b=b-x;
		}
		d[i]=i-y;
	}
	
	for(i=0;i<n;i++){
		if(d[i]>max1)
			max1=d[i];
	}
	cout<<max1;
	return 0;
} 
