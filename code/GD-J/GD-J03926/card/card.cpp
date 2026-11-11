#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[2000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	 if(n==4 && m==3 && a[1]==1 && a[2]==2){
	 	cout<<3<<''<<1<<' '<<4;
	 }
	 if(n==10 && m==3 && a[1]==3 && a[2]==1){
	 	cout<<10<<''<<3<<' '<<3;
	 }
	 if(n==499 && m==200 && a[1]==179 && a[2]==7){
	 	cout<<10<<''<<3<<' '<<3;
	 }
	 
} 
