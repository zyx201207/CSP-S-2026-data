#include<bits/stdc++.h>
using namespace std;
long long n,m,a[99999999],v=1;
bool o[9999999];
int tu(int x){
	int b;
	for(int i=1;x>=1;i++){
		o[i]=(x%2);
		x/=2;
		v++;
	}
	for(int i=v;i>=1;i--){
		b=(b*10)+o[i];
		o[i]=0;
	}
	return b;
}
int ad(int d,int f){
	int b=1,j;
	for(int i=1;i<=10000000;i*=10){
		j++;
		if(d%(i*100)-d%(i*10)==1&&f%(i*100)-f%(i*10)==1){
			o[j]=1;
		}
		else{
			o[j]=0;
		}
	}
	for(int i=j;i>=1;i--){
		b=(b*10)+o[i];
		o[i]=0;
	}
	return b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","r",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	for(int i=n+1;i>=n-m;i--){
		a[i]=ad(tu(a[i-1]),tu(a[i]));
	}
	cout<<ad(1011,1101);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
