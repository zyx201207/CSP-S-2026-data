#include<bits/stdc++.h>
using namespace std;
char a[10000001],b[10000001],p[10000001];
long long int m[10000001],n,l2=0,l=0,sum=0;
int main(){


freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(long long int i=1;i<=n;i++){
	cin>>m[i]>>p[i];
	l+=m[i];
	for(long long int j=1;j<=m[i];j++){
		l2++;
		a[l2]=p[i];
	}
	
}

for(long long int i=1;i<=l;i++){
b[i]=a[l-i+1];
		
}	

for(long long int i=1;i<=l/2;i++){
if(a[i]!=b[i]) sum++;

		
}	

cout<<sum;	


return 0;	
} 
