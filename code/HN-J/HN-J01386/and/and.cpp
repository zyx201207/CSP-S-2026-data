#include<bits/stdc++.h>
using  namespace  std;
const  int  M=2*1e5;
int  n,m;
int  a[M];
int max1=INT_MIN;
int  sum=0; 
void  init(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int  i=0;i<n;i++){
		cin>>a[i];
	}
}
void  solve(){
	for(int  i=0;i<n;i++){
		for(int  h=0;h<m;h++){
			for(int  j=i+1;j<n;j++){
				sum=0;
				sum+=(a[i]&a[j]);
				cout<<sum<<" ";
				if(sum>max1){
					max1=sum;
				}
			}
		}
	}
}
void  out(){
	cout<<max1;	
}
int  main(){
	init();
	solve();
	out();
	return  0;
}
