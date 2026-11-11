#include<bits/stdc++.h>
using namespace std;

int n;
long long m;
long long a[200010]={},b[200010]={};

int tmp(int a,int b){
	return a>b;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,tmp);
	int sqc=0;
	for(int i=2;i<=n;i++){
		b[i]=b[i-1]+(a[1]-a[i]);
	}
	
	for(int i=1;i<=n;i++){
		sqc=i;
		if(b[i]==m){

			printf("%d",i);
			return 0;
		}
		else if(b[i]>m){
			printf("%d",i-1);
			return 0;
		}
	}
	printf("%d",sqc);
	return 0;
}
