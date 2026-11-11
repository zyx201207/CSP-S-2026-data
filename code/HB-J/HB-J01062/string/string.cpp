#include <bits/stdc++.h>
using namespace std;
long long r=0;
long long n;
char a[1000000005];
char xs;
int x[200005];
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>x[i];
		cin>>a[i];
		ans=ans+x[i];}
	long long l1=x[0],r1=x[n-1],l2=0,r2=n-1;
	for(long long i=0;i<ans/2;i++){
		if(l1==0){
			l2++;
			l1=x[l2];}
		if(r1==0){
			r2--;
			r1=x[r2];}
		if(a[l2]!=a[r2]) r++;
		l1--;
		r1--;}
	cout<<r;
	return 0;
	}
