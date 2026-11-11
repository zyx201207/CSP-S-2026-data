#include<stdio.h> 
#include<iostream>
using namespace std;
long long n,m,a[200005],b[200005],c[200005],d[200005],l1,l2,sum,mmm;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&m);
		cin>>s;
		a[i]=s[0]-'a';
		b[i]=m;
		c[n-i+1]=a[i];
		d[n-i+1]=b[i];
	}
	l1=1,l2=1;
	while(l1<=n&&l2<=n){
		mmm=min(b[l1],d[l2]);
		if(a[l1]!=c[l2]){
			sum+=mmm;
		}
		if(b[l1]>d[l2]){
			l2++;
			b[l1]-=mmm;
		}else if(b[l1]<d[l2]){
			l1++;
			d[l2]-=mmm;
		}else{
			l1++;
			l2++; 
		}
	}
	printf("%lld",sum/2);
	return 0;
}
