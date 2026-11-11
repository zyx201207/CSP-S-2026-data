//GZ-S00404 ±Ï½ÚÁº²Å ºúçùçâ 
#include<bits/stdc++.h>
using namespace std;
int a[5000010];
int b[5000010];
int c[5000010];
long long  m,n,ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+1+n);
	int mid;
	int r=n;
	int l=1;
	if(n%2==0) mid=n/2;
	else mid=n/2+1;
	for(int j=1;j<mid;j++){
		b[mid]+=a[mid]-a[j];
	}
	if(b[mid]<m){
		l=mid;
		r=n;
	}
	if(b[mid]>m){
		r=mid;
		l=1;
	}
	if((r-l)%2==0) mid=l+(r-l)/2+1;
	else mid=l+(r-l)/2;
	
	for(int i=l;i<=r;i++){
		for(int j=1;j<i;j++){
			c[i]+=a[i]-a[j];
		}
	}
	for(int i=1;i<=n;i++){
		if(c[i]>m){
			cout<<i-1;
			break;
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
