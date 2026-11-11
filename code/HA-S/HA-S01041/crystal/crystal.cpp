#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N];
bool J1,J2,J3;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=i)J1=1;
	}
	if(n==0){
		printf("%d",n);
	}
	if(J1==0&&n!=0){
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=i-1;
			if(sum+i>m){
				printf("%d",i);
				return 0;
			}
			if(i==n&&sum+n-1<m){
				printf("%d",n);
			}
		}
	}
	else if(J1==1){
		int d=a[2]-a[1];
		for(int i=1;i<=n-1;i++){
			if(a[i+1]-a[i]!=d)J2=1;
			if(a[i+1]!=a[i])J3=1;
		}
		if(J3==0){
			printf("%d",n);
			return 0;
		}
		if(J2==0){
			int sum=0;
			for(int i=1;i<=n;i++){
				sum+=(i-1)*d;
				if(sum+i*d>m){
					printf("%d",i);
					return 0;
				}
				if(i==n&&sum+(n-1)*d<m){
					printf("%d",n);
				}
			}
		}	
	}
	return 0;
}
