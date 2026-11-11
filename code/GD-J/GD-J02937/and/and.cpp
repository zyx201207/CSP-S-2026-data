#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+100;
int a[N],n;
int And(int m,int q){
	int z=0;
	if(m==1)return a[q];
	for(int i=q+1;i<=n;i++){
		if(i==q)continue;
		z=max(z,a[q]&And(m-1,i));
	}
	return z;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int z=0;
	for(int i=1;i<=n-m+1;i++){
		z=max(z,And(m,i));
	}
	cout<<z;
	return 0;
}
