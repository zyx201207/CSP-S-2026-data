#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,Max=0;
void choose(int nc,int And,int np,int a[]){
	if(np>n){
		return;
	}
	if(nc==m){
		Max=max(Max,And);
		return;
	}
	if(nc==0){
		for(int i=1;i<=n-m+1;i++){
			choose(1,a[i],i,a);
		}
	}else{
		for(int i=np+1;i<=n-(m-nc)+1;i++){
			choose(nc+1,And&a[i],i,a);
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(nullptr);
	cin>>n>>m;
	int a[n+1]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}

	choose(0,0,1,a);
	cout<<Max;
	return 0;
}
