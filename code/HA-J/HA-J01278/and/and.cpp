#include<bits/stdc++.h>
using namespace std;
	long long n,m,a[200005],b[200005][55],aa,j=1,as;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
cin>>n>>m;
if(m==1){cin>>a[1];	for(int i=2;i<=n;i++){
		cin>>a[i];if(a[i]<a[i-1]){
			a[i]=a[i-1];
		}}
		cout<<a[n];
}else{

	for(int i=1;i<=n;i++){
		cin>>a[i];
		while(aa!=0){
			as=a[i]%2;
			aa=a[i]/2;
			a[i]=a[i]/2;
			b[i][j]=as;j++;
		}	
	}}
}
