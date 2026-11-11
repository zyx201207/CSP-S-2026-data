//GZ-J00515 邹俊杰 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],s,ma=-1;
int main(){
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	if(n<=20){
	for(int i=0;i<(1<<n);i++){
		long long p;
		bool f=false;
		int s=0;
		for(int j=0;j<i;j++){
			if(i&(1<<j)){
			if(f==false)p=a[j],f=true;	
			else p=p&a[j];
			s++; 
			}
		}
		if(s==m)
		ma=max(p,ma);
	}
	cout<<ma;	
	}
	else if(m==1){
		sort(a,a+n);
		cout<<a[n-1];
	}
	else if(m==n){
		long long l=a[0];
		for(int i=1;i<n;i++)
		l=l&a[i];
		cout<<l;
	}
	else if(m==2){
		sort(a,a+n);
		cout<<(a[n-1]&a[n-2]);
	}
	else{
		sort(a,a+n);
		cout<<a[n-m];
	}
	return 0;
} 
