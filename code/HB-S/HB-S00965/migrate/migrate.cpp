#include<bits/stdc++.h>
using namespace std;
long long n,m,p=1,a[5000001],ans=0,b[5000001],c[5000001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];}
	sort(a+1,a+1+n);
	for(long long i=2;i<=n;i++){
		long long w=1,j=0;
		while(j<=m){
			for(long long k=i-1;k>=1;k--){
				if(j+(a[i]-a[k])<=m){
					j=j+(a[i]-a[k]);
					w=w+1;
				}
				else{
					j=m+1;
				}
				if(k<1)j=m+1; 
			}
		}
		b[p]=w;
		p=p+1;
	}
	sort(b+1,b+p);
	//for(long long i=1;i<p;i++)
	cout<<b[p-2]<<" ";
	return 0;
}
