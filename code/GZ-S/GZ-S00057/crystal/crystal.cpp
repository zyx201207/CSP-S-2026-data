//GZ-S00057 遵义师范学院附属实验学校 唐浩然
#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,max=0,rmax=0,rm=0;
	cin>>n>>m;
	if(n<=5000){
	int a[n+1]={0},b[n+1]={0},c[n]={0};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n-1;i>=1;i--){
		b[i]=a[i+1]-a[i];
	}
	while(n!=0){
		rm=m;
		c[n-1]=b[n-1];
		for(int i=n-2;i>=1;i--){
			c[i]=c[i+1]+b[i];
		}
		int i=n-1;
		while(i>=1){
			if(c[i]<=rm){
				rm-=c[i];
				rmax++;
			}
			i--;
		}
		if(rmax+1>max){
			max=rmax+1;
		}
		rmax=0;
		n--;
	}
	cout<<max;
	}
	int a,b;
	cin>>a>>b;
	rmax=b-a;
	int i=1;
	while(m>=0&&i<=n){
		if(m>=i*rmax){
			m-=rmax*i;
			max++;
			i++;
		}
		else{
			m-=rmax*i;
		}
		cout<<max+1;
	}
	return 0;
}
