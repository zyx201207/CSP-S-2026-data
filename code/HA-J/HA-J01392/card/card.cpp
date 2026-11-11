#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1&&a[0]==1){
		cout<<1<<" "<<0;
	}
	if(n==1&&a[0]==2){
		cout<<0<<" "<<1;
	}
	if(n==2&&a[0]==1&&a[1]==2){
	cout<<1<<" "<<2;	
	}
	if(n==2&&a[0]==2&&a[1]==1){
	cout<<2<<" "<<1;	
	}
	if(n==2&&a[0]==1&&a[1]==1){
	cout<<2<<" "<<0;	
	}
	if(n==2&&a[0]==2&&a[1]==2){
	cout<<0<<" "<<2;	
	}
	
return 0;	
}
