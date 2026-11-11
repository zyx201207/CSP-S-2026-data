#include<bits/stdc++.h>
using namespace std;
int main(){
//freopen("and.in","r",stdin);
//freopen("and.out","r",stdout);
long long n,p=0,m,a[10000],d[10000],q=0,t[10000];
cin>>n>>m;
long long c[1000][1000],x[1000][1000];
for(int i=0;i<n;i++){
	cin>>a[i];
}
sort(a,a+n);
for(long long i=0;i<n;i++){
	while(a[i]>0){
	c[i][p]=a[i]%2;
	a[i]=a[i]/2;
	p++;
}
t[i]=p+1;
p=0;
}
long long y=1;
for(long long i=0;i<m;i+=2){
	for(long long s=0;s<t[n-y-1];s++){
		if(c[n-y-1][s]==1 and c[n-y][s]==1){
			d[s]=1;
		}
		else{
			d[s]=0;
		}
		q=s;
	}
	
	y++;
}
long long f=1,o=0;
	for(long long s=0;s<q;s++){
		o+=d[s]*f;
		f*=2;
}
cout<<o;
return 0;
}
