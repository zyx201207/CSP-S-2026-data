#include<bits/stdc++.h>
using  namespace  std;
const  int  M=5*1e5;
int  n,m;
int  sum=0;
int  a[M],b[M];
void  init(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int  i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int  i=0;i<n;i++){
		for(int  j=i;j<n;j++){
			b[sum++]=a[j];
		}
	}
}
void  solve(){
	for(int  i=0;i<sum;i++){
		
	}
}
void  out(){
		
}
int  main(){
	init();
	solve();
	out();
	return  0;
}
