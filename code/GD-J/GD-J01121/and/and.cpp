#include<bits/stdc++.h>
#define int long long
using namespace std;
int sum,a[10000001],n,m,ma,b;
void ljh(int i,int k,int sum){
	if(i==n+1){
		if(m==k) ma=max(sum,ma);
	}
	else{
		if(n-i+1<m-k) return ;
		if(k==0) ljh(i+1,k+1,a[i]);
		if(k<m) ljh(i+1,k+1,sum&a[i]);
		ljh(i+1,k,sum);
	}
}
main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
		if(a[i]==i-1) b++;	
	}
	ljh(1,0,0);
	cout<<ma;
}
