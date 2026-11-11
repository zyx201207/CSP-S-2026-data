//уейкаж GZ-J00067 
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[100000000];
bool px(int a,int b){
	return a>b;
}
long long maxa=0;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&a[i]);
	}
	for(int i=n-1;i>=1;--i){
		for(int j=1;j<=i;++j){
			if(a[j+1]>a[j]){
				int c=a[j+1];
				a[j+1]=a[j];
				a[j]=c;
			}
		}
	}
	
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=n;++j){
			if(a[i]&a[j]>maxa)maxa=a[i]&a[j];
		}
	}
	printf("%lld",maxa);
	return 0;
}
