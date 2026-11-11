#include <bits/stdc++.h>
using namespace std;
int a[10000005];
int c[10000005]={1};
int b[10000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ax=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		 ax=max(ax,a[i]);
		 c[i]=a[i]&c[i-1];
	}
	if(m==1){
		cout<<ax;
		return 0;
	}
	if(m==n){
		cout<<c[n];
		return 0;
	}
	int p=1;
	int ax2=0;
	for(int j=n;j>m;j--){
		b[p]=c[j]&c[j-m-1];
		ax2=max(ax2,b[p]);
		p++; 
	}
	cout<<ax2;
	return 0;
}
