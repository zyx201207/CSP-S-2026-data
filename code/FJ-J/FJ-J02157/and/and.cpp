#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
void q(long long g,long long w,long long s){
	if(s==m){
		if(g>ans){ans=g;}
		return;
	}
	for(long long i=w+1;i<n;i++){
		long long u=g&a[i];
		q(u,i,s+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);	
	cin>>n>>m;
	if(m==1){cout<<0;return 0;}
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		q(a[i],i,1);
	}
	cout<<ans;
	return 0; 
}
