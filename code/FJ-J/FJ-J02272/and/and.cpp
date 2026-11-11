#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l=0,k;
int a[500010];
int ss(int z,int x){
	if(x==0){
		return a[z]; 
	}
	for(int i=z+1;i<=n-x+1;i++){
		k=a[z]&ss(i,x-1);
		l=max(l,k);
		return k;
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			l=max(l,a[i]);
		}
	}else{
		for(int i=1;i<=n-m+1;i++){
			ss(i,m-1);
		}
	}
	cout<<l;
	return 0;
}
