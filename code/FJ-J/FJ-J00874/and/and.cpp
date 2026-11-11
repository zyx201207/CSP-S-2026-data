#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[200005],cnt,c[40],d[40],z;
int andn(int x,int y){
	int sum=0,sum1=0,sum2=0,t=0,s=1;
	while(x>0){
		sum+=1;
		c[sum]=x%2;
		x/=2;
	}
	while(y>0){
		sum1+=1;
		d[sum1]=y%2;
		y/=2;	
	}
	if(sum>sum1) sum2=sum1;
	else sum2=sum;
	for(int i=1;i<=sum2;i++){
		if(c[i]==1&&d[i]==1){
			for(int j=1;j<i;i++){
				s*=2;
			}
			t+=s;
		}	
	}
	return t;	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			if(a[i]>cnt) cnt=a[i];
		}
	}
	if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++){
				z=andn(i,j);
				if(z>cnt){
					cnt=z;
				}
					
			}
	}
	cout<<cnt;
	return 0;
}
