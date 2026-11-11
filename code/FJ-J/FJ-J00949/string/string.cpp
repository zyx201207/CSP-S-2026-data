#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],z,cn=0,cnt=0,b=1,x,j,i;
char c[200005];
int main (){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	for( i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cn+=a[i];
		z+=cn/2;
		cn=cn%2;
		while(z>a[b]){
			z-=a[b];
			b++;
		}
	}
	z++;
	while(z>a[b]){
			z-=a[b];
			b++;
	}
	if(cn==1){
		cn=0;
		x=1;
	}
	if(a[b]>z||(a[b]==z&&x==0))j=b;
	else j=b+1;
	if(1<z)i=b;
	else i=b-1;
	long long y1,y2,s1=1,s2=x;
	while(i==1&&j==n){
		if(i==j){
			if(a[j]-z+1-x>=z-1){
				i--;
				s1+=a[i+1];
			}
			else {
				j++;
				s2+=a[j-1];
			}
		}
		else {
			y1=a[i];
			y2=a[j];
			if(s1>=s2)y2=y2-s1+s2;
			else y1=y1-s2+s1;
			if(c[i]!=c[j]){
				cn+=min(y2,y1);
				cnt+=cn/1000000000;
				cn%=1000000000;
			}
			if(y1>=y2){
				j++;
				s2+=a[j-1];
			}
			else{
				i--;
				s1+=a[i+1];
			}
		}
	}
	y1=a[i];
			y2=a[j];
			if(s1>=s2)y2=y2-s1+s2;
			else y1=y1-s2+s1;
			if(c[i]!=c[j]){
				cn+=min(y2,y1);
				cnt+=cn/1000000000;
				cn%=1000000000;
			}
			if(y1>=y2){
				j++;
				s2+=a[j-1];
			}
			else{
				i--;
				s1+=a[i+1];
			}
	if(cnt!=0){
		cout<<cnt;
		for( i=10;i<=100000000;i*=10){
			if(cn<i)cout<<0;
		}
	}
	cout<<cn;
	return 0;
}
