//GZ-S00057 遵义师范学院附属实验学校 唐浩然
#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	int c,t;
	cin>>c>>t;
	
	while(t>0){
		int n,d,sum=0;
		cin>>n>>d;
		int a[n+1]={0},b[n+1]={0};
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=n;i>=2;i--){
			b[i]=a[i]-a[i-1];
		}
		int e[n+1][n+1];
		for(int i=0;i<=n;i++){
			for(int l=0;l<=n;l++){
				e[i][l]=0;
			}
		}
		for(int l=1;l<=n;l++){
			for(int i=l+1;i<=n;i++){
				if(b[i]<=d){
					e[i][l]=b[i]+e[i-1][l];
					e[l][i]=e[i][l];
				}
			}
	}
		for(int i=0;i<=n;i++){
			for(int l=0;l<=n;l++){
				if(e[i][l]==0){
					e[i][l]=1000000;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int k=i+1;k<=n;k++){
					if(e[i][k]>=e[i][k-1]+e[k-1][k]){
						e[i][k]=e[i][k-1]+e[k-1][k];
						e[k][i]=e[i][k];
				}
			}
			}
			int pan=0;
		for(int i=1;i<=n;i++){
			for(int k=i+2;k<=n;k++){
				for(int l=i;l<k;l++){
					for(int h=l;h<k;h++){
						if((e[i][k-h]+e[k-h][k]==e[i][k-l]+e[k-l][k])&&h!=l&&pan==0){
						sum++;
		pan=1;
	}
	if((e[i][k-h]+e[k-h][k]==e[i][k-l]+e[k-l][k])&&h!=l&&pan==1){
						sum--;
	pan=2;
	}
	
	pan=0;}}}
	}
	cout<<sum;
		t--;
}
}
