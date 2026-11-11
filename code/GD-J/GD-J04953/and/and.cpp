#include<bits/stdc++.h>
using namespace std;
int n,m,a[101010],f=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	sort(a,a+n,greater<int>());
	for(int i=0;i<n;i++){
		if(a[i]-1!=a[i-1])f=0;
		if(f==0)break;
	}
	if(m==1)printf("%d",a[0]);
	else if(n==m){
		int x=a[0];
		for(int i=1;i<n;i++){
			x=x&a[i];
		}
		printf("%d",x);
	}
	else if(m==2)printf("%d",a[0]&a[1]);
	else if(f==1)cout<<n-m;
	else{
		int x=a[0];
		for(int i=1;i<m;i++){
			x=x&a[i];
		}
		printf("%d",x);
	}
	return 0;
} 
