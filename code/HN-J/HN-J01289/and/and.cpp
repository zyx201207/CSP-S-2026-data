#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,mx=0,i;
	cin>>n>>m;
	long long a[n+5];
	for(i=0;i<n;i++){
		cin>>a[i];
		
	}
	if(m==1){
		for(i=0;i<n;i++){
			mx=max(mx,a[i]);
		}
		cout<<mx;
	}
	if(m==n){
		mx=a[0];
		for(i=1;i<n;i++){
			mx&=a[i];
		}
		cout<<mx;
	}
	return 0;
}
