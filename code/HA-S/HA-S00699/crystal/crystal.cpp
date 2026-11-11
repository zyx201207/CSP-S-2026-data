#include<bits/stdc++.h>
using namespace std;
long long n,m,l,k=1;
int main(){
	freopen("crystal.in","r",str.in);
	freopen("crystal.out","w",str.out);
	cin>>n>>m;
	long long a[n];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
for(int j=1;j<=n;j++){
for(int i=1;i<=n;i++){
	if(a[i]>a[i+1]){
	l=a[i];
	a[i]=a[i+1];
	a[i+1]=l;
	}
}
}
for(int i=1;i<=n;i++){
	if(m>=0){
	if(i*(a[i+1]-a[i])<=m){
	m-=i*(a[i+1]-a[i]);
	k++;
	
	}
	}
	
	
}
cout<<k;
}

