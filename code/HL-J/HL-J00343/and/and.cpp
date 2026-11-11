#include<bits/stdc++.h>
using namespace std;
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long n,m,a[200005],s=0,Max,k,xb;
int max(int a,int b){
	if(a>b) return a;
	return b;
}
int main(){
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long c=1;c<=n;c++){
		Max=a[c];
		while(s!=m){
			k=Max&a[1]; 
			for(long long i=1;i<=n;i++){
				k=max(k,Max&a[i]);
				xb=i;
			}
			for(long long i=xb;i<n;i++){
				a[i]=a[i+1];
			}
			Max=k;
			s++;
		}	
	}
	cout<<k;
	return 0;
}
