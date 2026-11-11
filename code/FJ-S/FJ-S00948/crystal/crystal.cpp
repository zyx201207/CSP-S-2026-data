#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstring>
#include<cstdio> 
#define int long long
using namespace std; 
int read(){
	int sumer=0;
	int p=1;
	char t;
	do{
		t=getchar();
		if(t=='-') p=-1;
		if(t<='9'&&t>='0') sumer=sumer*10+t-'0';
	}while(t=='-'||(t<='9'&&t>='0'));
	return sumer*p;
}
int n,m,A[500001],B[500001],maxn=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	B[0]=0;
	n=read();
	m=read();
	for(int i=1;i<=n;i++) A[i]=read();
	sort(A+1,A+1+n);
	for(int i=1;i<=n;i++){
		B[i]=B[i-1]+A[i];
	}
	for(int r=1,l=1;r<=n;r++){
		while((r-l)*A[r]-(B[r-1]-B[l-1])>m&&l<r) l++;
		maxn=max(r-l+1,maxn);
	}
	cout<<maxn;
	return 0;
}
/*
5 8
-3 -1 2 2 7
*/
